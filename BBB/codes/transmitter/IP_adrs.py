import os 	
#The os module provides dozens of functions for interacting with the 
#operating system 
import LCD	
#The LCD module provides dozens of functions for interacting with the LCD 
import time
#Time module provides various time-related functions.

ipv4_eth0 = os.popen('ip addr show eth0').read().split("inet ")[1].split("/")[0]

#uncomment below statement to read loop back addresss
#ipv4_lo = os.popen('ip addr show lo').read().split("inet ")[1].split("/")[0]

#uncomment below statement to read USB0 IP addresss
#ipv4_usb0 = os.popen('ip addr show usb0').read().split("inet ")[1].split("/")[0]

#LCD PIN INTERFCAE
lcd_rs = 'P8_8'
lcd_en = 'P8_10'
lcd_d4 = 'P8_18'
lcd_d5 = 'P8_16'
lcd_d6 = 'P8_14'
lcd_d7 = 'P8_12'

lcd_columns = 16
lcd_rows = 2

#LCD initialization
lcd = LCD.CharLCD(lcd_rs,lcd_en,lcd_d4,lcd_d5,lcd_d6,lcd_d7,
lcd_columns,lcd_rows)

# messages to print on LCD
lcd.message('Sigma Hightech')
time.sleep(2)
lcd.clear()

lcd.message('SSH IP is :\n')
lcd.message(ipv4_eth0)
time.sleep(5)
lcd.clear()

#remove both """ to print Loopback address 
"""
lcd.message('Loopback IP is :\n')
lcd.message(ipv4_lo)
time.sleep(5)
lcd.clear()
"""

#remove both """ to print usb ip adress
"""
lcd.message('USB IP is :\n')
lcd.message(ipv4_usb0)
time.sleep(5)
lcd.clear()
"""
#print(ipv4_eth0,ipv4_lo,ipv4_usb0)
