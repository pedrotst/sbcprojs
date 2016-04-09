CC=gcc
CFLAGS=-I. -std=c99 -g -O0
SOURCE=./src
OBJ = ./obj/Debug/src

all: main movemain

main: base62.o base64.o base91.o moveobj
	$(CC) $(CFLAGS) -o main $(SOURCE)/main.c $(OBJ)/base62.o $(OBJ)/base64.o $(OBJ)/base91.o

base62.o: 
	$(CC) $(CFLAGS) $(SOURCE)/base62.h $(SOURCE)/base62.c -c

base64.o:
	$(CC) $(CFLAGS) $(SOURCE)/base64.h $(SOURCE)/base64.c -c

base91.o:
	$(CC) $(CFLAGS) $(SOURCE)/base91.h $(SOURCE)/base91.c -c

moveobj:
	mv ./*.o ./obj/Debug/src/

movemain:
	cp ./main ./bin/Debug/SBProject


