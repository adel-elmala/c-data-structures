#ifndef __LINKEDLIST_H
#define __LINKEDLIST_H

#include <cstddef>
#include <iostream>

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


#endif