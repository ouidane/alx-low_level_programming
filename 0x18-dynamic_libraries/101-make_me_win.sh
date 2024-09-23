#!/bin/bash
wget -P /tmp https://github.com/ouidane/alx-low_level_programming/blob/main/0x18-dynamic_libraries/win.so
export LD_PRELOAD=/tmp/win.so