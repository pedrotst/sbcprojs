CC=gcc
CFLAGS=-I. -std=c99 -g -O0
SOURCE=./src
OBJ = ./obj/Debug/src

all: main movemain

main: utils.o moveobj
	$(CC) $(CFLAGS) -o main $(SOURCE)/main.c $(OBJ)/utils.o -lm	

utils.o: 
	$(CC) $(CFLAGS) $(SOURCE)/utils.h $(SOURCE)/utils.c -c -lm

moveobj:
	mkdir -p ./obj/Debug/src/
	mv ./*.o ./obj/Debug/src/

movemain:
	mkdir -p ./bin/Debug/SBProject
	cp ./main ./bin/Debug/SBProject
