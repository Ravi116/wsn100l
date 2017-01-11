from tkinter import *
from tkinter import ttk
import serial,serial.tools.list_ports

root = Tk()
root.title("WSN monitoring")

def connect(*args):
    ports = list(serial.tools.list_ports.comports())
    for p in ports:
        print(p)
    print("Connected to " )
    print(str(com_port.get()))
    

mainframe = ttk.Frame(root,padding = "30 30 12 12")
mainframe.grid(column = 0 , row = 0 ,sticky = (N,W,E,S))
mainframe.columnconfigure(0,weight = 1)
mainframe.rowconfigure(0,weight = 1)

com_port = StringVar()
baud = StringVar()

com_port_entry = ttk.Entry(mainframe,width = 7 ,textvariable = com_port )
com_port_entry.grid(column = 3 ,row = 1,sticky = (W,E))

baud_entry = ttk.Entry(mainframe,width = 7 ,textvariable = baud)
baud_entry.grid(column = 3,row = 2 ,sticky = (W,E))

ttk.Button(mainframe,text = "Connect",command = connect).grid(column =3 ,row =3,sticky = (W,E))

ttk.Label(mainframe , text = "COM PORT : ").grid(column = 2 ,row = 1,sticky = (E))
ttk.Label(mainframe, text = "Baud Rate : ").grid(column = 2 ,row = 2 ,sticky =(E))

for child in mainframe.winfo_children():child.grid_configure(padx =5 ,pady = 5)
com_port_entry.focus()
root.bind('<Return>',connect)

#ttk.Button(root,text = "hello world").grid()
root.mainloop()
 
