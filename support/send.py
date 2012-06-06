## send.py
## Brad Osgood
## Jun 3 2012
## Send serial data over the terminal

import serial
import sys

ser = serial.Serial(sys.argv[1], 9600, timeout=1)

while True:
    input = raw_input('> ')
    ser.write(input)