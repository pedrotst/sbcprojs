CC=gcc
CFLAGS=-I.
SOURCE=./src
OBJ = ./obj/Debug/src

all: main move

main: base62.o
	$(CC) -std=c99 -o main $(SOURCE)/main.c $(OBJ)/base62.o 

base62.o: 
	$(CC) -std=c99 $(SOURCE)/base62.h $(SOURCE)/base62.c -c

move: movemain moveobj

moveobj:
	mv ./*.o ./obj/Debug/src/

movemain:
	cp ./main ./bin/Debug/SBProject


