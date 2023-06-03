CC:=gcc
CFLAGS:=-O3 -pipe
LIBS:=-lm -lwayland-server -lswc
OUT:=fun-compositor

COMP:=$(CC) $(CFLAGS) -c
LINK:=$(CC) *.o $(LIBS) -o $(OUT)

OBJS:=main.o screen.o window.o

all: $(OBJS)
	$(LINK)
	strip $(OUT)

main.o: src/main.c
	$(COMP) $(NVIDIA) src/main.c

screen.o: src/screen.c src/screen.h
	$(COMP) $(NVIDIA) src/screen.c

window.o: src/window.c src/window.h
	$(COMP) $(NVIDIA) src/window.c

nvidia:
	make -E "NVIDIA=-D NVIDIA"

clean:
	rm *.o
	rm $(OUT)

