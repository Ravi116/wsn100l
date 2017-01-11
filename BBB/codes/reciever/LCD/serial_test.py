import Adafruit_BBIO.UART as UART
import serial 
import time
import CharLCD as LCD
UART.setup("UART4") 

# pin configuration
lcd_rs = 'P8_8' 
lcd_en = 'P8_10'
lcd_d4 = 'P8_12'
lcd_d5 = 'P8_14'
lcd_d6 = 'P8_16'
lcd_d7 = 'P8_18'

lcd_columns = 16
lcd_rows = 2
lcd = LCD.CharLCD(lcd_rs,lcd_en,lcd_d4,lcd_d5,lcd_d6,lcd_d7,
lcd_columns, lcd_rows)





ser = serial.Serial(port = "/dev/ttyO4",baudrate=9600)
ser.close()
ser.open()
while(1):
 if ser.is_open:
	print"Serial is open!"
	lcd.message("Serial is open")
#	data = ser.read(ser.in_waiting or 1)
	data = ser.read(ser.in_waiting)
	if data:
		print(data)
		lcd.message("\n Reading Data")
	time.sleep(2)
	lcd.clear()
 else:
  print"Serial fail"
ser.close()
