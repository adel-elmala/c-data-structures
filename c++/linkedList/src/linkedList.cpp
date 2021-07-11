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
std::size_t linkedList<dataType>::size()const{
    return this->listSize;
}

// bool returns true if empty


template<typename dataType>
bool linkedList<dataType>::empty() const{
    return this->listSize == 0;
}



// returns the value of the nth item (starting at 0 for first)
template<typename dataType>
dataType& linkedList<dataType>::operator[](std::size_t index)
{
    // check if in bounds
    if((this->listSize) - 1 < index)
    {
        logError("out of bounds");
        this->~linkedList();
        exit(0);
    }
    node<dataType>* current = this->head;
    
    std::size_t idx = 0;
    while(current != nullptr){
        if(idx == index)
            return current->data;
        else
        {
            current = current->next;
            ++idx;
        }
    }
}


template<typename dataType>
const dataType& linkedList<dataType>::operator[](std::size_t index) const
{
    // check if in bounds
    if((this->listSize) - 1 < index)
    {
        logError("out of bounds");
        this->~linkedList();
        exit(0);
    }
    
    node<dataType>* current = this->head;
    
    std::size_t idx = 0;
    while(current != nullptr){
        if(idx == index)
            return current->data;
        else
        {
            current = current->next;
            ++idx;
        }
    }
}

// insert value at index, so current item at that index is pointed to by new item at index
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
    if(this->listSize == 0)
        tail = newNode;
    this->head= newNode;
    this->listSize += 1; 
}

//  remove front item and return its value

template<typename dataType>
dataType linkedList<dataType>::pop_front(void){
    // check  if not empty
    if(empty()){
        logError("List is Empty");
        this->~linkedList();
        exit(1);
    }
    node<dataType>* firstNode = this->head;
    this->head = firstNode->next;
    this->head->prev = nullptr;
    dataType tmpData = firstNode->data;
    delete firstNode;
    this->listSize -= 1 ;
    return tmpData;
}

template<typename dataType>
void linkedList<dataType>::prettyPrint(void) const{
    
    node<dataType> * current = head;
    std::size_t idx = 0;
    
    std::cout << "[";
    while(current != nullptr)
    {
        if(idx % 15 == 0 && (idx != 0))
            std::cout << std::endl;
        
        std::cout << this->operator[](idx)<<" ,";   
        current = current->next; 
        ++idx;
    }
    std::cout << "]\n";
}



// adds an item at the end

template<typename dataType>
void linkedList<dataType>::push_back(dataType& item)
{
    node<dataType>* newNode = new(node<dataType>);
    // node<dataType>* tmp = tail;
    // fill newNode data 
    newNode->data = item;
    newNode->next = nullptr;
    newNode->prev = tail;
    // check if  empty list
    if((tail == nullptr) && (head == nullptr)){
        // change head too if empty
        head = newNode;
    }
    else{
        // change last node data
        printf("not empty\n");
        tail->next = newNode;
        // printf("not empty\n");

    }
    tail = newNode;
    this->listSize += 1;
}

// removes end item and returns its value

template<typename dataType>
dataType linkedList<dataType>:: pop_back(void){
    dataType tmp = tail->data;
    node<dataType>* tmpTail = tail;
    
    // check if empty
    if(tmpTail == nullptr)
    {
        logError("Empty List");
        this->~linkedList();
        exit(1);
    }
    //  update tail
    tail = tail->prev;
    tail->next = nullptr;
    this->listSize -= 1;
    // free last node
    delete tmpTail;
    return tmp;
}


// get value of front item
template<typename dataType>
dataType linkedList<dataType>::front(void) const 
{
    checkEmpty();
    return head->data;

}


// get value of end item
template<typename dataType>
dataType linkedList<dataType>::back(void)const
{
    checkEmpty();
    return  tail->data;

}



// removes node at given index
template<typename dataType>
void linkedList<dataType>::erase(std::size_t index){
    checkEmpty();
    // check if in bounds
    if(index > (listSize - 1))
    {
        logError("out of bounds index!");
        this->~linkedList();
        exit(1);
    }
    if(index == 0){
        pop_front();
        return;
    }
    if(index == (listSize -1)){
        pop_back();
        return;
    }
    node<dataType>* wantedNode = nullptr;
    // start from end
    if(index > (listSize / 2))
    {   
        logInfo("starting from end!");
        wantedNode = tail;
        size_t i= (listSize - 1);
        while(i > index){
            wantedNode = wantedNode->prev;
            --i;
        }
    }
    // start from head
    else{

        logInfo("starting from beginning!");
        wantedNode = head;
        size_t i = 0;
        while(i < index){
            wantedNode = wantedNode->next;
            ++i;
        }
    }

    wantedNode->prev->next = wantedNode->next;
    wantedNode->next->prev = wantedNode->prev;
    delete wantedNode;
    listSize -= 1;
}

// removes node at given index
template<typename dataType>
inline void linkedList<dataType>::checkEmpty(void)
{
    // check if empty
    if(this->listSize == 0)
    {
        logError("Empty List");
        this->~linkedList();
        exit(1);
    }

}

// // returns the value of the node at nth position from the end of the list

// template<typename dataType>
// dataType linkedList<dataType>:: value_n_from_end(std::size_t n);
    
// reverses the list

// template<typename dataType>
// void linkedList<dataType>::reverse(void);
   
// //  removes the first item in the list with this value

// template<typename dataType>
// void linkedList<dataType>::remove_value(dataType value);