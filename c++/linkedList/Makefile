CC = g++
CFLAGS = -g -Wall  -pedantic 

SRC = 	src/testLL.cpp \
		src/linkedList.cpp

UTILS = "../../utils/logger/src/logger.c"

HEADERS = include/linkedList.h
INCLUDE = -I "./include" 
INCLUDE += -I "../../utils/logger/include"

BIN = ./bin/testLL.out

testLL:$(SRC) $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDE) $(SRC) $(UTILS) -o $@ 
	# mv $@ ./bin


.PHONY:setupDir,clean,valgrind
setupDir:
	mkdir bin src include 
	mv *.cpp ./src
	mv *.h ./include
clean:
	rm bin/*
valgrind:
	valgrind --leak-check=full --show-leak-kinds=all ./bin/testLL



