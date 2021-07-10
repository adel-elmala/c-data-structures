#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "vector.h"

typedef struct 
{
    data_t * data;
    size_t currentSize;
    size_t maxCapacity;
} vector;


void* createVector(size_t initCapacity){
    
    // alloc memory of vector struct
    vector* vec = (vector *) malloc(sizeof(vector));
    
    // init vec meta-data
    vec->currentSize = 0;
    vec->maxCapacity = initCapacity;
    
    // alloc memory of data items
    size_t dataMemSize = sizeof(data_t) * initCapacity;
    data_t * dataMem = (data_t*) malloc(dataMemSize);
    
    // populate the mem with the initial value of zero
    memset((void *)dataMem, 0, dataMemSize);
    vec->data = dataMem;

    return (void*) vec;
}

void destroyVector(void* vec){
    
    vector* v = (vector*) vec; 
    free(v->data);
    free(v);
}

// number of items
size_t size(void* vec){

    vector* v = (vector*) vec; 
    return v->currentSize;
}

// number of items it can hold
size_t capacity(void* vec){

    vector* v = (vector*) vec; 
    return v->maxCapacity;
}

bool is_empty(void* vec){

    vector* v = (vector*) vec; 
    return (v->currentSize == 0);
}

//returns item at given index, blows up if index out of bounds
data_t at(void* vec,size_t index){
    
    vector* v = (vector*) vec; 
    // no nedd to check below zero as this would cause a compiler error (i.e unsigned long is always >= 0)
    if((index <= (v->currentSize)) )
    {

        return (v->data)[index];
    }
    
    else
    {
        // TODO: Change printing to a logger system 
        fprintf(stderr,"Error: Out of bounds indexing:%lu\n", index);
        exit(1);

    }
} 



//same as 'at' except it allows indexing up to the capacity of the vector
data_t at_all(void* vec,size_t index){
    
    vector* v = (vector*) vec; 
    // no nedd to check below zero as this would cause a compiler error (i.e unsigned long is always >= 0)
    if((index <= (v->maxCapacity)) )
    {

        return (v->data)[index];
    }
    
    else
    {
        // TODO: Change printing to a logger system 
        fprintf(stderr,"Error: Out of bounds indexing:%lu\n", index);
        exit(1);

    }
}

// private function
void* resize(void* vec,size_t newCapacity){
    
    vector* v = (vector*) vec; 
    // alloc memory of data items
    data_t * newDataMem = (data_t*) malloc(newCapacity * sizeof(data_t));
    memset((void *)newDataMem, 0, newCapacity * sizeof(data_t));

    data_t * oldDataMem = v->data;
    // copy data from old to new memory
    memcpy((void *)newDataMem, (const void *)oldDataMem,(v->currentSize) * sizeof(data_t));
    free(oldDataMem);
    v->data = newDataMem;
    v->maxCapacity = newCapacity;
    return (void*)vec;
} 
// first checks if the data mem is full ,then resizes it to the double 
void updateCapacity(void* vec){

    vector* v = (vector*) vec; 
    if(v->maxCapacity == v->currentSize)
        // double the vector capacity
        resize(v,(v->maxCapacity) * 2);
}


void push(void* vec,data_t *item){

    vector* v = (vector*) vec; 
    // check capacity
    updateCapacity(vec);
    size_t currentSize = v->currentSize;
    // push item
    (v->data)[currentSize] = *item;
    // update size
    v->currentSize = currentSize + 1;
}

// inserts item at index, shifts that index's value and trailing elements to the right
void insert(void* vec,size_t index, data_t *item){
    vector* v = (vector*) vec; 

    for(size_t i = ((v->currentSize) - 1); i != (index - 1); --i){
        fprintf(stdout,"in");
        (v->data)[i + 1] = (v->data)[i];
    }
    (v->data)[index] = *item;
    v->currentSize += 1; 
}

// can use insert above at index 0
void prepend(void* vec,data_t *item){
    insert(vec,0,item);
}


//  delete item at index, shifting all trailing elements left and return the value
data_t deleteAndReturn(void* vec,size_t index){
    vector* v = (vector*) vec; 
    
    data_t val = (v->data)[index];
    if(v->currentSize == 0){
        fprintf(stderr,"Error: Empty vector\n");
        exit(1);
    }

    size_t lastIndex = v->currentSize - 1;
    // check index bounds
    if(lastIndex < index){
        fprintf(stderr,"Error: out of bounds index: %lu,\tVector's size is: %lu\n",index,lastIndex);
        exit(1);
    }
    data_t* baseAddr = v->data;

    for(size_t i = index;i <= lastIndex; ++i){
        baseAddr[i] = baseAddr[i + 1];
    }
    // decrement size
    v->currentSize = lastIndex ;
    return val;
}


// remove from end, return value
data_t pop(void* vec){
    return deleteAndReturn(vec,0);
}

//  delete item at index, shifting all trailing elements left
void delete(void* vec,size_t index){
    deleteAndReturn(vec,index);
}

// TODO: finish this 


// performs a linear search to and returns all indecies for the desired item (in a vector :D)
void* findAll(void* vec,data_t* item){
    vector* v = (vector*) vec;
    size_t last = v->currentSize; 
    void * indiciesVec = createVector(last);
    
    // ignore warning for now
    for(int i = 0;i < last;++i)
    {
        if((v->data)[i] == *item)
            push(indiciesVec,&i);
    }
    return indiciesVec; 
}


// looks for value and removes index holding it (even if in multiple places)
void removeAll(void* vec,data_t* item){

    vector* indiciesVec = (vector*) findAll(vec,item);
    size_t last = (indiciesVec->currentSize);
    for(size_t i = last - 1;i < last;--i){
        delete(vec,(indiciesVec->data)[i]);
    }
    destroyVector(indiciesVec);
}

// looks for value and returns first index with that value, -1 if not found
size_t find(void* vec,data_t *item){
    vector* indecies = (vector*)findAll(vec,item);
    size_t firstIndex = indecies->data[0];
    destroyVector(indecies);
    return firstIndex;
}