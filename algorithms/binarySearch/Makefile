CC = g++
CFLAGS = -g -Wall  -pedantic 

SRC = 	tests/testBS.c \
		src/binarySearch.c 

HEADERS = include/binarySearch.h
UTILS = "../../utils/logger/src/logger.c"
		


INCLUDE = -I "./include" 
INCLUDE += -I "../../utils/logger/include"

BIN = ./bin/

testHT:$(SRC) $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDE) $(SRC) $(UTILS) -o $(BIN)$@ 
	# mv $@ ./bin


.PHONY:setupDir,clean,valgrind

setupDir:
	mkdir bin tests include 
	mv *.cpp ./tests
	mv *.h ./include
clean:
	rm bin/*
valgrind:
	valgrind --leak-check=full --show-leak-kinds=all $(BIN)testHT



