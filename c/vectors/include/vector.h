#ifndef _VECTOR_H
#define _VECTOR_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../../common/common.h"

// change this typedef to the desired vec_item type (i.e. char, int , float , struct,...) 
typedef int data_t;



void* createVector(size_t initCapacity);

void destroyVector(void* vec);

// number of items
size_t size(void* vec);

// number of items it can hold
size_t capacity(void* vec);

bool is_empty(void* vec);

//returns item at given index, blows up if index out of bounds
data_t at(void* vec,size_t index);

// private function
void* resize(void* vec,size_t newCapacity);
// first checks if the data mem is full ,then resizes it to the double 
void updateCapacity(void* vec);


void push(void* vec,data_t *item);

//inserts item at index, shifts that index's value and trailing elements to the right
void insert(void* vec,size_t index, data_t *item);

// can use insert above at index 0
void prepend(void* vec,data_t *item);

//  remove from end, return value
data_t pop(void* vec);

//  delete item at index, shifting all trailing elements left
void delete(void* vec,size_t index); 


// looks for value and returns first index with that value, -1 if not found
size_t find(void* vec,data_t *item);


//  delete item at index, shifting all trailing elements left and returns the value of the deleted element
data_t deleteAndReturn(void* vec,size_t index);


// performs a linear search to and returns all indecies for the desired item (in a vector :D)
void* findAll(void* vec,data_t* item);

// looks for value and removes index holding it (even if in multiple places)
void removeAll(void* vec,data_t* item);



#endif