CC=gcc
CFLAGS=-I. -std=c99 -g -O0
SOURCE=./src
OBJ = ./obj/Debug/src

all: main movemain

main: main.o moveobj
	$(CC) $(CFLAGS) -o main $(OBJ)/main.o -lm

main.o:
	$(CC) $(CFLAGS) -c $(SOURCE)/main.c -lm
	

base62.o: 
	$(CC) $(CFLAGS) $(SOURCE)/base62.h $(SOURCE)/base62.c -c -lm

moveobj:
	mv ./*.o ./obj/Debug/src/

movemain:
	cp ./main ./bin/Debug/SBProject


