CFLAGS  = -Wall -Werror
OBJ = build/main.o build/funks.o
OB = build/main_test.o build/funks.o
FUNCS = src/funks.c

default: build bin bin/game bin/game-test clean

test: bin/game-test
	./bin/game-test

run1: bin/game
	./bin/game

run2: bin/game-test
	./bin/game-test

bin/game: $(OBJ) bin
	gcc $(CFLAGS) $(OBJ) -o bin/game

build/main.o: src/main.c build
	gcc $(CFLAGS) -c src/main.c -o build/main.o

build/funks.o: src/funks.c build
	gcc $(CFLAGS) -c src/funks.c -o build/funks.o

bin/game-test: $(OB) build
	gcc $(CFLAGS) $(OB) -o bin/game-test

build/main_test.o: tests/main_test.c lib/ctest.h src/funks.h build
	gcc -Wall -I lib -I src -c ./tests/main_test.c -o ./build/main_test.o

build:
	mkdir -p build

bin:
	mkdir -p bin

.PHONY:
	clean

clean:
	rm -rf build bin
