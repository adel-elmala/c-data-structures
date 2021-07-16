#ifndef __HASHTABLE_H
#define __HASHTABLE_H

#include "logger.h"
#include "linkedList.h"
#include <math.h> 

// enum Flag {EMPTY,DELETEME};
// template<typename valueType>
// struct tableElement{
//     const char* key;
//     valueType value;
//     Flag flag; 
// };



template<typename valueType>
class hashTable
{
private:
    unsigned int tableSize;
    
    linkedList<valueType>* hTable;
    // converts the key into a unsigned int 
    unsigned long int prehash(const char* k){
        if (k == nullptr)
        {
            logError("NULL pointer encountered!");
            exit(1);
        }
        unsigned  long int prehashValue = 0;
        unsigned int counter = 0;
        while(k[counter] != '\0')
        {
            prehashValue += (double)k[counter] * pow(11,counter);
            ++counter;
        }
        // std::cout << "prehash is: " << prehashValue << std::endl;
        return prehashValue;
    } 
    
    unsigned int hash(const char* k){
        
        unsigned long int prehashValue = prehash(k);
        return (prehashValue % tableSize);
    }
    
public:
    hashTable(unsigned int size):tableSize(size)
    {
        hTable = new linkedList<valueType>[size];
    };
    ~hashTable(){
        delete[] hTable;
    }
    // if key already exists, update value
    void add(const char* key, valueType& value){
        unsigned int idx = hash(key);
        // logInfo("Adding at index:");
        // std::cout << idx << std::endl;
        // hTable[idx].remove_value(value);
        hTable[idx].push_front(value);
    }
    bool exists(const char* key){
        // hTable[hash(k)];
        return false;
    }
    valueType& get(const char* key){return false;}
    bool remove(const char* key){return false;}


    void prettyPrintHT(void){
        for(int i = 0; i < tableSize ; ++i)
        {
            hTable[i].prettyPrint();
        }
    }

};




#endif // __HASHTABLE_H