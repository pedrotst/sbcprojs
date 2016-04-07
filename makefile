CC=gcc
CFLAGS=-I.
SOURCE=./src
OBJ = ./obj/Debug/src

all: main

main: base62.o base64.o move
	$(CC) -std=c99 -o main $(SOURCE)/main.c $(OBJ)/base62.o $(OBJ)/base64.o

base62.o: 
	$(CC) -std=c99 $(SOURCE)/base62.h $(SOURCE)/base62.c -c

base64.o:
	$(CC) -std=c99 $(SOURCE)/base64.h $(SOURCE)/base64.c -c

move: movemain moveobj

moveobj:
	mv ./*.o ./obj/Debug/src/

movemain:
	cp ./main ./bin/Debug/SBProject


