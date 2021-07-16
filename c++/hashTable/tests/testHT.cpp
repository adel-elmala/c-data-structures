#include <iostream>
#include "hashTable.h"


using namespace std;
int main(int argc, char** argv){

    logInfo("Begin Testing Hashtable\n");
    hashTable<unsigned int> ht(20);
    unsigned int values[5] = {0,1,2,3,999};
    logStartLine("test (add)");
    
    ht.add("first element",values[0]);
    ht.add("second element",values[1]);
    ht.add("third element",values[2]);
    ht.add("forth element",values[3]);
    ht.add("forth element",values[4]);

    ht.prettyPrintHT();
    logEndLine();

    return 0;
}
