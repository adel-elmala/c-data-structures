CC = g++
CFLAGS = -g -Wall  -pedantic 

SRC = 	src/testDA.cpp 
		

UTILS = "../../utils/logger/src/logger.c"

HEADERS = include/DynamicArray.h

INCLUDE = -I "./include" 
INCLUDE += -I "../../utils/logger/include"

BIN = ./bin/testDA

testDA:$(SRC) $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDE) $(SRC) $(UTILS) -o $@ 
	# mv $@ ./bin



.PHONY:setupDir,clean,valgrind
setupDir:
	mkdir bin src include 
	mv *.cpp ./src
	mv *.h ./include
clean:
	rm ./bin/*
valgrind:
	valgrind --leak-check=full --show-leak-kinds=all ./testLL



