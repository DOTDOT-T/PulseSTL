#ifndef PULSESTL_VECTOR_H
#define PULSESTL_VECTOR_H

#include <stdexcept>

#include "iterator/iterator.h"

namespace PulseLibs::STL
{
    template<typename Object>
    class Vector
    {
    public:
        Vector()
        {
            item = new Object[capacity];
            size = 0;
        }

        ~Vector()
        {
            delete[] item;
        }

#pragma region INSERTION AND DELETE

        void Pushback(Object obj)  //for now, the pushback will only insert to the last position, next step -> return the iterator
        {
            Resize();

            item[size] = obj;
            ++size;
        }

        void Insert(Object item, int index)
        {
            Resize();
        }

#pragma endregion

#pragma region UTILITIES

        /**
         * @brief Resize will only resize the vector if we got at the limit of the vector.
         * 
         */
        void Resize()
        {
            if (size >= capacity)
            {
                // simple reallocation: double capacity
                int newCapacity = capacity * 2;
                Object *newBlock = new Object[newCapacity];

                // first copy the content of item into the new vector
                for (int i = 0; i < size; ++i)
                    newBlock[i] = item[i];

                // we dont need anymore the item vector so we can erase it to then assign it to the new block.
                delete[] item;
                item = newBlock;
                capacity = newCapacity;
            }
        }

#pragma endregion

#pragma region ACCESSOR

        Object& Back()
        {
            if (size == 0)
                throw std::out_of_range("Vector is empty");
        
            return item[size - 1];
        }
        Iterator<Object> Last()
        {
            if (size == 0)
                throw std::out_of_range("Vector is empty");
        
            return Iterator<Object>{ item + (size - 1) };
        }

        Iterator<Object> Begin() { return Iterator<Object>{ item }; }
        Iterator<Object> End()   { return Iterator<Object>{ item + size}; }

        Object& operator[](int index)
        {
            return item[index];
        }

        int Size() const { return size; }
        int Capacity() const { return capacity; }        

#pragma endregion

    private:    
        Object* item;           // pointer to the first object
        int     size = 0;       // size give us the amount of object in the vector
        int     capacity = 10;  //the capacity indicate the total amount of value possible to insert in the vector before needing to reallocate it
    };
};

#endif