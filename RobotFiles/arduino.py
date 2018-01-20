#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
import serial
import os

def get_serial_port():
    return "/dev/" + os.popen("dmesg | egrep ttyACM | cut -f3 -d: | tail -n1").read().strip()

if len(sys.argv) == 1:
    sys.exit(1)

else:
    if "--help" in sys.argv:
        print("type: 'python arduino.py <startLine/stopLine/dance>'")
        sys.exit(0)

    else:
        if sys.argv[1] == 'startLine' or sys.argv[1] == 'stopLine' or sys.argv[1] == 'dance':
            ser = serial.Serial(get_serial_port(), baudrate=115200)
            ser.write(sys.argv[1].strip())
            ser.close()
            sys.exit(0)

        else:
            sys.exit(1)
