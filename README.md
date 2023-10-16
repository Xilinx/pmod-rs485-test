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

## Build Instructions

- Install build pre-requisites

    ```bash
        sudo apt install libmodbus-dev
    ```

- Clone the repo

    ```bash
        git clone https://github.com/Xilinx/pmod-rs485-test.git
        cd pmod-rs485-test
    ```

- Build and Install

    ```bash
        sudo make install [prefix=<installation prefix path>]
    ```
    
    The Application will be installed in bin directory inside the prefix path.
    Default prefix is '/opt/xilinx/pmod-rs485-test' hence the default installation path is `/opt/xilinx/pmod-rs485-test/bin`.

    e.g. `sudo make install prefix=$HOME/install` will install the application in `/home/<usrname>/install/bin`.

    >Make sure to add the `<prefix>/bin/` to the PATH variable to access the application by its name.

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
