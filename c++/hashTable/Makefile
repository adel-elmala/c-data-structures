CC = g++
CFLAGS = -g -Wall  -pedantic 

SRC = 	tests/testHT.cpp \
		include/hashTable.h 


UTILS = "../../utils/logger/src/logger.c"
		


INCLUDE = -I "./include" 
INCLUDE += -I "../../utils/logger/include"
INCLUDE += -I "../linkedList/include/"

BIN = ./bin/

testHT:$(SRC) $(dependencies)
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



