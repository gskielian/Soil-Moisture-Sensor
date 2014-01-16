#!/usr/local/bin/python

import serial, time
ser = serial.Serial('/dev/tty.usbmodem1421', 115200, timeout = 0.1)

def send( theinput ):
  ser.write( theinput )
  while True:
    try:
      time.sleep(0.01)
      #state = ser.readline()
      #print state
      break
    except:
      pass
  time.sleep(0.1)

def send_and_receive( theinput ):
  ser.write( theinput )
  while True:
    try:
      time.sleep(0.01)
      state = ser.readline()
      print state
      return state
    except:
      pass
  time.sleep(0.1)

while True:
  f = open('dataFile.txt','a')
  f.write(send_and_receive('1'))
  f.close()
  time.sleep(1)

