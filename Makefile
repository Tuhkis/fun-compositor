CC=gcc
CFLAGS=-O3 -pipe
LIBS=-lm -lwayland-server -lswc
OUT=func-wm

COMP=$(CC) $(CFLAGS) -c

all: main.o
	$(CC) *.o $(LIBS) -o $(OUT)
	strip $(OUT)

main.o: src/main.c
	$(COMP) src/main.c

clean:
	rm *.o
	rm $(OUT)

