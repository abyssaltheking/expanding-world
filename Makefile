CC=clang
CFLAGS=
LIBS=-lglfw -lGL
OUTNAME=idfk.o

SRC=$(wildcard src/*.c) libs/glad/glad.c

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