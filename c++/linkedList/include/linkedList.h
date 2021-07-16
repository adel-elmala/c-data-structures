#ifndef __LINKEDLIST_H
#define __LINKEDLIST_H

#include <cstddef>
#include <iostream>
#include "logger.h"


template <typename dataType>
struct node
{
    dataType data;
    node<dataType>* next;
    node<dataType>* prev;
};


template <typename dataType>
class linkedList
{
private:
    inline void checkEmpty(void) const;

    node<dataType> * head;
    node<dataType> * tail;
    std::size_t listSize;
public:
    linkedList();
    ~linkedList();

    // returns number of data elements in list
    std::size_t size() const;
    
    // bool returns true if empty
    bool empty() const;
    
    // returns the value of the nth item (starting at 0 for first)
    dataType& operator[](std::size_t index);
    const dataType& operator[](std::size_t index) const;
    
    // // insert value at index, so current item at that index is pointed to by new item at index
    // insert(index, value);
    
    
    //  adds an item to the front of the list
    void push_front(dataType& item);

    //  remove front item and return its value
    dataType pop_front(void);

    // adds an item at the end
    void push_back(dataType& item);
    
    // removes end item and returns its value
    dataType pop_back(void);

    // get value of front item
    dataType front(void) const;

    // get value of end item
    dataType back(void) const;
    
    // removes node at given index
    void erase(std::size_t index);
    
    // returns the value of the node at nth position from the end of the list
    dataType value_n_from_end(std::size_t n) const;
    
    // reverses the list
    void reverse(void);
   
    //  removes the first item in the list with this value
    void remove_value(dataType value);
   
    void prettyPrint(void) const;
};







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


template<typename dataType>
inline void linkedList<dataType>::checkEmpty(void) const
{
    // check if empty
    if(this->listSize == 0)
    {
        logError("Empty List");
        this->~linkedList();
        exit(1);
    }

}


// returns the value of the node at nth position from the end of the list
template<typename dataType>
dataType linkedList<dataType>:: value_n_from_end(std::size_t n) const {

    node<dataType> * target = tail;

    while(n != 0)
    {
        target = target->prev;
        --n;
    }
    return target->data;

}
    

// reverses the list
template<typename dataType>
void linkedList<dataType>::reverse(void){
    node<dataType>* current = head;
    node<dataType>* tmp = nullptr;
    // std::size_t length = listSize;
    if(this->empty()){
        logWarning("List is Empty");
        return;
    }
    while(current != nullptr)
    {
        tmp = current->next;
        current->next = current->prev;
        current->prev = tmp;
        current = tmp;
    }
    tmp = head;
    head = tail;
    tail = tmp;
    return;
}
   
//  removes the first item in the list with this value

template<typename dataType>
void linkedList<dataType>::remove_value(dataType value){
    if(this->empty())
    {
        logWarning("Empty List!");
        return;
    }

    node<dataType>* current = head;
    std::size_t size = listSize;
    std::size_t idx = 0;
    while(current != nullptr)
    {
        if(current->data == value)
            erase(idx);
        ++idx;
        current = current->next;
    }
    if(listSize ==size )
    {
        logWarning("Value is not found in the List");
        return;
    }
}


#endif
