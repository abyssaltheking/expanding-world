CC=clang
CFLAGS=
LIBS=-lSDL3
OUTNAME=idfk.o

SRC=$(wildcard src/*.c) $(wildcard src/**/*.c)

all:
	mkdir -p build
	$(CC) $(CFLAGS)  $(SRC) $(LIBS) -o build/$(OUTNAME)

run:
	./build/$(OUTNAME)

debug:
	valgrind ./build/$(OUTNAME)

quick:
	mkdir -p build
	$(CC) $(CFLAGS)  $(SRC) $(LIBS) -o build/$(OUTNAME)
	./build/$(OUTNAME)

clean:
	rm -rf build/*