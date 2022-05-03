# PMOD RS485 Test
===============

An Example application to demonstrate RS485 functionality over Xilinx Axi Uartlite.

Following sensor is used for this example:

R444A01 Digital display RS485 Modbus RTU temperature and humidity sensor.
Check the aliexpress link for the detail datasheet of the sensor.

## Links:
- [Aliexpress](https://www.aliexpress.com/item/33054683552.html)
- [Amazon](https://www.amazon.com/Temperature-Humidity-Sensor-Display-Modbus/dp/B078NRYBVZ)

## Dependency:
- HW: Uartlite IP is patched to support RS485
- SW: libmodbus (build dependency)

## Build:

`make`

## Install:

`sudo make install [DESTDIR=<installation path>]`

`sudo` is needed only if DESTDIR requires privileged access.

Default destination directory for the install (DESTDIR) is `/usr/bin`.

## Usage:

`sudo pmod-rs485-test [<Device>]`

Where Optional __**Device**__ is the uart device to be used for the test.
Default device is `/dev/ttyULR0`

E.g
`sudo pmod-rs485-test /dev/ttyULR0`

## License

```
Copyright (C) 2022 Xilinx, Inc. All rights reserved.
SPDX-License-Identifier: MIT
```
