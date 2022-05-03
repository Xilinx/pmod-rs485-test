#*****************************************************************************
# Copyright (C) 2022 Xilinx, Inc. All rights reserved.
# SPDX-License-Identifier: MIT
#******************************************************************************
#
# Makefile to build pmod-test application
#
APP = pmod-test

# Add any other object files to this list below
APP_OBJS = pmod-test.o

LDLIBS += -lmodbus

all: build

build: $(APP)

$(APP): $(APP_OBJS)
	$(CC) -o $@ $(APP_OBJS) $(LDFLAGS) $(LDLIBS)
clean:
	rm -f $(APP) *.o

