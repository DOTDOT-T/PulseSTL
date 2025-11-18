#ifndef PULSESTL_VECTOR_H
#define PULSESTL_VECTOR_H

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

        void Pushback(Object obj)  //for now, the pushback will only insert to the last position, next step -> return the iterator
        {
            Resize();

            item[size] = obj;
            ++size;
        }

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

        void Insert(Object item, int index)
        {
            Resize();
        }

        Object& operator[](int index)
        {
            return item[index];
        }

    private:    
        Object* item;           // pointer to the first object
        int     size = 0;       // size give us the amount of object in the vector
        int     capacity = 10;  //the capacity indicate the total amount of value possible to insert in the vector before needing to reallocate it
    };
};

#endif