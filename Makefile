CC=clang
CFLAGS=
LIBS=-lcsfml-window -lGL
OUTNAME=idfk.o

SRC=$(wildcard src/*.c)

all:
	mkdir -p build
	$(CC) $(CFLAGS)  $(SRC) $(LIBS) -o build/$(OUTNAME)

run:
	./build/$(OUTNAME)

quick:
	mkdir -p build
	$(CC) $(CFLAGS)  $(SRC) $(LIBS) -o build/$(OUTNAME)
	./build/$(OUTNAME)

clean:
	rm -rf build/*