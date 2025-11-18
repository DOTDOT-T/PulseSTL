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

        PulseLibs::STL::Iterator Back()
        {
            try
            {
                if(size-1 < 0 ) throw std::out_of_range("vector is empty. Couldn't return the last item.");
                return PulseLibs::STL::Iterator(item[size-1]);
            }
            catch(const std::out_of_range& e)
            {
                std::cout << std::endl << e.what() << std::endl;
                return nullptr;
            }
        }

        Object& operator[](int index)
        {
            return item[index];
        }

#pragma endregion

    private:    
        Object* item;           // pointer to the first object
        int     size = 0;       // size give us the amount of object in the vector
        int     capacity = 10;  //the capacity indicate the total amount of value possible to insert in the vector before needing to reallocate it
    };
};

#endif