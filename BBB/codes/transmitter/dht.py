import LCD
import Adafruit_BBIO as GPIO
import Adafruit_BBIO.UART as UART
import serial
import Adafruit_DHT
import time

UART.setup("UART1")

lcd_rs = 'P8_8'
lcd_en = 'P8_10'
lcd_d4 = 'P8_18'
lcd_d5 = 'P8_16'
lcd_d6 = 'P8_14'
lcd_d7 = 'P8_12'

lcd_columns = 16
lcd_rows = 2

sensor = 11
pin = 'P8_7'

lcd = LCD.CharLCD(lcd_rs,lcd_en,lcd_d4,lcd_d5,lcd_d6,lcd_d7,
lcd_columns,lcd_rows)

lcd.message('Sigma Hightech')

ser = serial.Serial(port = "/dev/ttyO1",baudrate=9600)

def display(num1,num2):
   lcd.clear()
   lcd.set_cursor(0,0)
   lcd.message('Temp. = ')
   lcd.message(str(num1))
   lcd.message(' C')
   time.sleep(1)
   lcd.set_cursor(0,1)
   lcd.message('Humidity =')
   lcd.message(str(num2))
   lcd.message(' %')
   time.sleep(1)
   lcd.clear()

def frame(num,num1):
	node_id = "@1"
	tail = ";"
	s = ":"
	seq = (node_id,str(num),str(num1))
	fram = s.join(seq) + tail
#	print(fram)
	return fram;

def transmit_data(str1,len):
	 if ser.is_open:
#		print(len)
		ser.write(str(len))
		time.sleep(1)
                ser.write(str1)
                time.sleep(1)

while(1):
  humidity,temperature = Adafruit_DHT.read_retry(sensor,pin)
  if(humidity is not None and temperature is not None):
	display(temperature,humidity)
	data = frame(temperature,humidity)	
	transmit_data(data,len(data))
