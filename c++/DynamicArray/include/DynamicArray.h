#ifndef _DYNAMICARRAY_H
#define _DYNAMICARRAY_H

#include <stddef.h>
#include "logger.h"
#include <stdlib.h>
#include <string.h>
// typedef int T;

namespace AlgoAdel
{
    template <typename T>
    class DynamicArray
    {
    private:
        /* data */
        size_t maxCapacity;
        size_t currentSize;
        T *data;

        // when you reach capacity, resize to double the size
        // when popping an item, if size is 1/4 of capacity, resize to half (TODO)
        void resize(size_t new_capacity);

    public:
        DynamicArray();
        ~DynamicArray();

        // number of items
        size_t size(void);

        // number of items it can hold
        size_t capacity(void);

        bool is_empty(void);

        // returns item at given index, blows up if index out of bounds
        T &operator[](unsigned int index);
        const T &operator[](unsigned int index) const;

        // inserts item at index, shifts that index's value and trailing elements to the right
        void insert(unsigned int index, T item);

        // insert at the end of the array
        void push(T item);

        // can use insert above at index 0
        void prepend(T item);

        // -------- TODO  -------

        // remove from end, return value
        T pop(void);

        // delete item at index, shifting all trailing elements left
        void deleteItem(size_t index);

        // looks for value and removes index holding it (even if in multiple places)
        void remove(T item);

        // looks for value and returns first index with that value, -1 if not found
        long find(T item);

        void prettyPrint(void);
    };

} // namespace AlgoAdel

namespace AlgoAdel
{
    template <typename T>
    DynamicArray<T>::DynamicArray()
    {
        currentSize = 0;
        maxCapacity = 8;
        data = (T *)malloc(sizeof(T) * maxCapacity);
        // memset((void*)data,5,sizeof(T) * maxCapacity);
        bzero((void *)data, sizeof(T) * maxCapacity);
        logInfo("HELLO from constructor!!!\n");
    }

    template <typename T>
    DynamicArray<T>::~DynamicArray()
    {
        currentSize = 0;
        free(data);
        maxCapacity = 0;
        logInfo("BYE from deconstructor!!!\n");
    }

    template <typename T>
    size_t DynamicArray<T>::size(void)
    {
        return currentSize;
    }

    template <typename T>
    size_t DynamicArray<T>::capacity(void)
    {
        return maxCapacity;
    }

    template <typename T>
    bool DynamicArray<T>::is_empty(void)
    {
        return (currentSize == 0);
    }
    template <typename T>
    T &DynamicArray<T>::operator[](unsigned int index)
    {
        // check index is in-bounds
        if (index < maxCapacity)
            return *(data + index);
        else
        {
            logError("Out of bounds index [%u], Vector size is [%lu]!.\n", index, currentSize);
            exit(EXIT_FAILURE);
        }
    }
    template <typename T>
    const T &DynamicArray<T>::operator[](unsigned int index) const
    {
        // check index is in-bounds
        if (index < maxCapacity)
            return *(data + index);
        else
        {
            logError("Out of bounds index [%u], Vector size is [%lu]!.\n", index, currentSize);
            exit(EXIT_FAILURE);
        }
    }

    template <typename T>
    void DynamicArray<T>::resize(size_t new_capacity)
    {
        logInfo("Resizing from [%lu] to capacity [%lu]\n", maxCapacity, new_capacity);
        T *newData = (T *)malloc(sizeof(T) * new_capacity);
        // memset((void*)newData,0,sizeof(T) * new_capacity);
        bzero((void *)newData, sizeof(T) * new_capacity);
        for (size_t i = 0; i < maxCapacity; ++i)
        {
            *(newData + i) = *(data + i);
        }
        maxCapacity = new_capacity;
        free(data);
        data = newData;
    }

    // TODO: restrict inserting into random indicies , making the vector sparse
    template <typename T>
    void DynamicArray<T>::insert(unsigned int index, T item)
    {
        logInfo("Inserting at index [%u]\n", index);
        // check index is in-bounds
        if (index < maxCapacity)
        {
            // check if inserting from the back
            if (index >= currentSize)
            // no shift needed
            {
                // *(data + (sizeof(T) * index)) = item;
                *(data + currentSize) = item;
            }
            else // have to shift to left
            {
                T *target = data + index;
                for (T *i = (data + (currentSize - 1)); i >= target; --i)
                {
                    *(i + 1) = *i;
                }

                *(data + index) = item;
            }
            ++currentSize;
        }
        else // resize
        {
            resize(maxCapacity * 2);
            insert(index, item); //try again
        }
    }

    template <typename T>
    void DynamicArray<T>::push(T item)
    {
        insert(currentSize, item);
    }

    template <typename T>
    void DynamicArray<T>::prepend(T item)
    {
        insert(0, item);
    }

    template <typename T>
    void DynamicArray<T>::prettyPrint(void)
    {

        fprintf(stdout, "[ ");
        for (unsigned int i = 0; i < maxCapacity; ++i)
        {
            if (((i % 8) == 0) && (i > 0))
            {
                fprintf(stdout, "\n  ");
                fprintf(stdout, "%d ,", *(data + i));
            }

            else
            {
                // fprintf(stdout, "prettyPrinting\n");
                // fprintf(stdout, "%d ,", (*this)[i]);
                fprintf(stdout, "%d ,", *(data + i));
            }
        }
        fprintf(stdout, " ]\n");
    }

    template <typename T>
    T DynamicArray<T>::pop(void)
    {
        T tempValue = (*this)[currentSize - 1];
        (*this)[currentSize - 1] = 0;
        --currentSize;
        return tempValue;
    }

    template <typename T>
    void DynamicArray<T>::deleteItem(size_t index)
    {
        if (index < maxCapacity)
        {
            for (T *i = data + index; i < data + (maxCapacity - 1); ++i)
            {
                *(i) = *(i + 1);
            }
            --currentSize;
        }
        else
        {
            logError("Out of bounds index [%lu], vector capacity is [%lu]", index, maxCapacity);
            exit(EXIT_FAILURE);
        }
    }

}

#endif
