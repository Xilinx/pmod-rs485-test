/***************************************************************
* Copyright (C) 2022 Xilinx, Inc. All rights reserved.
* SPDX-License-Identifier: MIT
***************************************************************/

#include <stdio.h>
#include <modbus/modbus.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_DEVICE	"/dev/ttyULR0"

int main(int argc, char **argv)
{
	modbus_t *ctx;
	uint16_t sensor_reg[4];
	int total_reg = 2;
	char device_name[20];

	uint32_t to_sec;
	uint32_t to_usec;
	int rc, i;

	if (argc != 2) {
		strcpy(device_name, DEFAULT_DEVICE);
	} else {
		strcpy(device_name, argv[1]);
	}

	printf("RS-485 Pmod Test!\n");

	printf("Compiled with libmodbus version %s (%06X)\n",
			LIBMODBUS_VERSION_STRING, LIBMODBUS_VERSION_HEX);
	printf("Linked with libmodbus version %d.%d.%d\n",
			libmodbus_version_major, libmodbus_version_minor,
			libmodbus_version_micro);

	printf ("Create new communication channel\n");
	ctx = modbus_new_rtu(device_name, 9600, 'N', 8, 1);

	if (ctx == NULL) {
		fprintf(stderr, "Unable to create the libmodbus context\n");
		return -1;
	}

	/* set debug mode for verbose operation */
	modbus_set_debug(ctx, TRUE);

	/* Increate the response timeout to be on the safeside */
	modbus_get_response_timeout(ctx, &to_sec, &to_usec);

	printf ("Default Response timeout %d.%d\n", to_sec, to_usec);

	to_sec = 3;
	to_usec = 5000;
	if(modbus_set_response_timeout(ctx, to_sec, to_usec)) {
		fprintf(stderr, "Unable to set the response timeout\n");
		return -1;
	}

	modbus_get_response_timeout(ctx, &to_sec, &to_usec);
	printf ("New Response timeout %d.%d\n", to_sec, to_usec);

	/* Initialize and connect to the channel */
	modbus_connect(ctx);

	/* Set communication mode as RTU_RS485 */
	/*
	Commenting this function for now to make it work for Ubuntu 24.04 since driver
	already has RS485 mode enabled
	TODO : Debug uartlite-rs485 to check why below function call fails on KR260

	rc = modbus_rtu_set_serial_mode(ctx, MODBUS_RTU_RS485);
	if (rc == -1) {
		fprintf(stderr, "serial mode failed: %s\n", modbus_strerror(errno));
		modbus_free(ctx);
		return -1;
	}
	*/

	printf ("Setting Slave address\n");
	rc = modbus_set_slave(ctx, 1);

	if (rc != 0) {
		fprintf(stderr, "%s\n", modbus_strerror(errno));
		return -1;
	}

	printf ("Reading the Temperature & Humidity values\n");
	rc = modbus_read_registers(ctx, 0, total_reg, sensor_reg);

	if (rc == -1) {
		fprintf(stderr, "Read register Failed: %s\n", modbus_strerror(errno));
		return -1;
	}

	for (i = 0; i < total_reg; i++) {
		printf("reg[%d]=%d (0x%X)\n", i, sensor_reg[i], sensor_reg[i]);
	}

	printf("Temperature: %.1f Deg C\n", ((float) sensor_reg[0]) / 10 );
	printf("Humidity: %.1f %%\n", ((float) sensor_reg[1]) / 10 );

	modbus_close(ctx);
	modbus_free(ctx);

	return 0;
}
