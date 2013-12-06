CC=gcc
CFLAGS=`pkg-config --cflags gtk+-3.0` -O2 -Wall
GTKLIBS=`pkg-config --libs gtk+-3.0`
prefix=/usr/local

all: phenomenon.c
		$(CC) -o phenomenon $(CFLAGS) phenomenon.c $(GTKLIBS)