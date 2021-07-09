CC = gcc
CFLAGS = -Wall -Wextra -pedantic 

SRC = 	src/main.c \
		src/vector.c


HEADERS = include/vector.h
INCLUDE = -I "./include" 
INCLUDE += -I "../common"

BIN = ./bin/main.out

main:$(SRC) $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDE) $(SRC) -o $@ 
	mv $@ ./bin

# vector:src/vector.c include/vector.h 
# 	$(CC) $(CFLAGS) $(INCLUDE) $< -o $@ 


.PHONY:setupDir,clean,valgrind
setupDir:
	mkdir bin src include 
	mv *.c ./src
	mv *.h ./include
clean:
	rm bin/*
valgrind:
	valgrind --leak-check=full --show-leak-kinds=all ./bin/main



