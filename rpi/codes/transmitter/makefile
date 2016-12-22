CC = gcc
CFLAGS = -g -Wall
LIBS = -lwiringPi -lwiringPiDev


receive : transmitter.c
	$(CC) $(CFLAGS) -o transmit transmitter.c $(LIBS)
clean:
	$(RM)transmit
	
