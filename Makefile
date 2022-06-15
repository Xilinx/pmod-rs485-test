#*****************************************************************************
# Copyright (C) 2022 Xilinx, Inc. All rights reserved.
# SPDX-License-Identifier: MIT
#******************************************************************************
#
# Makefile to build pmod-test application
#
APP = pmod-rs485-test

prefix = /opt/xilinx/pmod-rs485-test
bindir = $(prefix)/bin

# Add any other object files to this list below
APP_OBJS = rs485-test.o

LDLIBS += -lmodbus

all: build

build: $(APP)

$(APP): $(APP_OBJS)
	$(CC) -o $@ $(APP_OBJS) $(LDFLAGS) $(LDLIBS)

.PHONY: install
install: $(APP)
	install -d $(DESTDIR)$(bindir)
	install -m 0755 $(APP) $(DESTDIR)$(bindir)

.PHONY: clean
clean:
	rm -f $(APP) *.o

