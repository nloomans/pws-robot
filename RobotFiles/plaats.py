#!/usr/bin/env python
# -*- coding: utf-8 -*-

import serial
ser = serial.Serial('/dev/ttyACM0',9600)
ser.write("333")
ser.close()
