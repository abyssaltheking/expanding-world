CC=clang
CFLAGS=
LINK=-lSDL3 -lSDL3_image -lm
OUTNAME=idfk.o
LIBS=$(wildcard libs/*.c) $(wildcard libs/**/*.c)
SRC=$(wildcard src/*.c) $(wildcard src/**/*.c)

all:
	mkdir -p build
	$(CC) $(CFLAGS) $(LIBS) $(SRC) $(LINK) -o build/$(OUTNAME)

run:
	./build/$(OUTNAME)

debug:
	valgrind ./build/$(OUTNAME)

quick:
	mkdir -p build
	$(CC) $(CFLAGS) $(LIBS) $(SRC) $(LINK) -o build/$(OUTNAME)
	./build/$(OUTNAME)

clean:
	rm -rf build/*