CC = gcc
CFLAGS = -g -Wall
LIBS = -lwiringPi -lwiringPiDev


receive : reciever.c
	$(CC) $(CFLAGS) -o recieve reciever.c $(LIBS)
clean:
	$(RM)recieve
	
