#include "binarySearch.h"
#include "logger.h"

// int predicate(data_t item1,data_t item2);
    // returns:
    //     0  if item1 == item2;
    //     1  if item1 >  item2;
    //     -1 if item1 <  item2;
        
unsigned int binarySearch(data_t* inputArray,data_t* target,funcPtr predicate,unsigned int min,unsigned int max){

    if (min > max)
    {
        logError("target value not found!\n");
        return -1;
    }

    unsigned int midpoint = (min + max)/2;
    int result = predicate(inputArray[midpoint],*target);
    if(result == 0) // inputArray[midpoint] == target
        return midpoint;

    else if(result == -1) // inputArray[midpoint] < target
        binarySearch(inputArray,target,predicate,midpoint + 1, max);
    else //// inputArray[midpoint] > target
        binarySearch(inputArray,target,predicate,0,midpoint - 1);

}
