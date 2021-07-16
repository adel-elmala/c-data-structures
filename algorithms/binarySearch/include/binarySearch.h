#ifndef __BINARYSEARCH_H
#define __BINARYSEARCH_H

#include "common.h"

typedef int data_t;
typedef int(*funcPtr)(data_t,data_t) ;

unsigned int binarySearch(data_t* inputArray,data_t* target,funcPtr predicate,unsigned int min,unsigned int max);



#endif // __BINARYSEARCH_H