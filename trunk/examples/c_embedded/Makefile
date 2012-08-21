TARGET = example01
CC = gcc
LDLIBS=`pkg-config --libs gtk+-2.0 gmodule-2.0`
CFLAGS=-Wall -g `pkg-config --cflags gtk+-2.0 gmodule-2.0`

all:
	$(CC) -o $(TARGET) $(TARGET).c $(LDLIBS) $(CFLAGS)
	echo "Multi-line text from file tmp.txt:" > inputfile
	echo "\`1234567890-=  ~!@#$%^&*()_+" >> inputfile
	echo "qwertyuiop[]\  QWERTYUIOP{}|" >> inputfile
	echo "asdfghjkl;'  ASDFGHJKL:\"" >> inputfile
	echo "zxcvbnm,./  ZXCVBNM<>?" >> inputfile

clean:
	rm $(TARGET)
	rm inputfile
