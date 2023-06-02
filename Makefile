CC:=gcc
CFLAGS:=-O3 -pipe
LIBS:=-lm -lwayland-server -lswc
OUT:=func-wm

COMP:=$(CC) $(CFLAGS) -c
LINK:=$(CC) *.o $(LIBS) -o $(OUT)

OBJS:=main.o

all: $(OBJS)
	$(LINK)
	strip $(OUT)

main.o: src/main.c
	$(COMP) $(NVIDIA) src/main.c

clean:
	rm *.o
	rm $(OUT)

