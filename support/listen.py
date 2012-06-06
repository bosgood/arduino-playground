## listen.py
## Brad Osgood
## Jun 3 2012
## Listen for serial connections, print to terminal

import serial
import sys

ser = serial.Serial(sys.argv[1], 9600, timeout=1)

while True:
    input = ser.readline()
    if input != '':
        print input