#include "logger.h"
#include "binarySearch.h"

int intPredicate(int item1 ,int item2){
    if(item1 == item2)
        return 0;
    else if(item1 >  item2)
        return 1;
    else 
        return -1;
}

int main(int argc, char**argv){


    logStartLine("begin tests for Binary Search");

    // int testInput[10] = {0};
    int testInput[10] = {0,2,4,5,6,8,10,13,15,17};
    // int testInput[10] = {};

    int target = 5;
    unsigned int result = binarySearch(testInput,&target,intPredicate,0,9);
    logInfo("target %d index: %d\n",target,result);

    target = 66;
    result = binarySearch(testInput,&target,intPredicate,0,9);
    logInfo("target %d index: %d\n",target,result);
    
    target = 0;
    result = binarySearch(testInput,&target,intPredicate,0,9);
    logInfo("target %d index: %d\n",target,result);

    
    target = 15;
    result = binarySearch(testInput,&target,intPredicate,0,9);

    logInfo("target %d index: %d\n",target,result);
    
    target = 17;
    result = binarySearch(testInput,&target,intPredicate,0,9);
    logInfo("target %d index: %d\n",target,result);



    return 0;
}