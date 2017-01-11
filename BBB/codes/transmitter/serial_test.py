import Adafruit_BBIO.UART as UART
import serial
import time

UART.setup("UART1")

ser = serial.Serial(port = "/dev/ttyO1",baudrate=9600)
ser.close()
ser.open()
data = 'SIGMA HIGHTECH'
data_length = len(data)
while(1):
 if ser.is_open:
	print"Serial is open!"
	ser.write(str(data_length))
	#print data_length
	time.sleep(2)
	ser.write(data)
	time.sleep(2)
 else:
  print"Serial fail"
ser.close()
