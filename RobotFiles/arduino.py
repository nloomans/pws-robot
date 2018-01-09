#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
import serial

if len(sys.argv) == 1:
    # print("err")
    sys.exit(1)

else:
    if "--help" in sys.argv:
        print("type: 'python arduino.py <startLine/stopLine/dance>'")
        sys.exit(0)

    else:
        if sys.argv[1] == 'startLine' or sys.argv[1] == 'stopLine' or sys.argv[1] == 'dance':
            ser = serial.Serial('/dev/ttyACM0', 115200)
            ser.write(sys.argv[1])
            ser.close()
            # print("err")
            sys.exit(0)
        else:
            # print("err")
            sys.exit(1)
