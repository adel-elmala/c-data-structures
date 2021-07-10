#include <iostream>
#include "logger.h"
#include "linkedList.h"



template<typename dataType>
linkedList<dataType>::linkedList()
{
    logInfo("constructor!");

    this->head = nullptr;
    this->tail = nullptr;
    this->listSize = 0;
}

template<typename dataType>
linkedList<dataType>::~linkedList(void)
{
    logInfo("destructor!");

    node<dataType>* current = this->head;
    // node<dataType>* tail = this->tail;
    node<dataType>* tmp = nullptr;
    
    std::size_t listSize = this->listSize;
    std::size_t counter = 0;
    
    // delete list nodes
    while(current != nullptr){
        tmp = current;
        current = tmp->next;
        delete tmp;
        ++counter;
    }
    // delete dummy nodes
    // delete this->head;
    // delete this->tail;
    if(counter != listSize)
        logError("list is not freed properly");
}



// returns number of data elements in list

template<typename dataType>
std::size_t linkedList<dataType>::size(){
    return this->listSize;
}

// bool returns true if empty


template<typename dataType>
bool linkedList<dataType>::empty(){
    return this->listSize == 0;
}



// returns the value of the nth item (starting at 0 for first)
template<typename dataType>
dataType& linkedList<dataType>::operator[](std::size_t index){
    // check if in bounds
    if(index > (this->listSize)){
            logError("out of bounds");
            this->~linkedList();
            exit(0);
    }
    node<dataType>* current = this->head;
    node<dataType>* tail = this->tail;
    
    std::size_t idx = 0;
    while(current != tail){
        if(idx == index)
            return current->data;
        else
        {
            current = current->next;
            ++idx;
        }

    }
    
}


// template<typename dataType>
// const dataType& linkedList<dataType>::operator[](std::size_t index) const{

// }

// // // insert value at index, so current item at that index is pointed to by new item at index
// insert(index, value);



//  adds an item to the front of the list
template<typename dataType>
void linkedList<dataType>::push_front(dataType& item){
    node<dataType>* newNode = (node<dataType>*) new(node<dataType>);
    newNode->data = item;
    newNode->next = this->head;
    newNode->prev = nullptr;
    if(this->listSize != 0)
        this->head->prev = newNode;

    this->head= newNode;
    this->listSize += 1; 
}

// //  remove front item and return its value

// template<typename dataType>
// dataType linkedList<dataType>::pop_front(void);

// // adds an item at the end

// template<typename dataType>
// void linkedList<dataType>::push_back(dataType& item);

// // removes end item and returns its value

// template<typename dataType>
// dataType linkedList<dataType>:: pop_back(void);

// // get value of front item

// template<typename dataType>
// dataType linkedList<dataType>::front(void);

// // get value of end item

// template<typename dataType>
// dataType linkedList<dataType>::back(void);

// // removes node at given index

// template<typename dataType>
// void linkedList<dataType>::erase(std::size_t index);

// // returns the value of the node at nth position from the end of the list

// template<typename dataType>
// dataType linkedList<dataType>:: value_n_from_end(std::size_t n);
    
// reverses the list

// template<typename dataType>
// void linkedList<dataType>::reverse(void);
   
// //  removes the first item in the list with this value

// template<typename dataType>
// void linkedList<dataType>::remove_value(dataType value);