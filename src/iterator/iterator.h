#ifndef PULSE_STL_ITERATOR_H
#define PULSE_STL_ITERATOR_H

namespace PulseLibs::STL
{

    /**
     * @brief Simple interator structure to use correctly and easily all the different container of the PSTL
     * 
     * @tparam Object the type of object the iterator is refering to
     */
    template<typename Object>
    struct Iterator
    {
        //usefull using to easily understand the iterator class
        using reference = Object&;
        using pointer = Object*;
        
        Object* ptr;

        reference operator*() const { return *ptr; }
        pointer operator->() const { return ptr; }
        Iterator<Object>& operator++() { (++ptr); return *this; } //prefix
        Iterator<Object> operator++(int) //postfix (usefull for loop usage)
        {
            Iterator<Object> tmp = *this;
            ++ptr;
            return tmp;
        }
        bool operator ==(const Iterator<Object>& other) { return ptr == other.ptr; }
        bool operator !=(const Iterator<Object>& other) { return ptr != other.ptr; }

    };
};

#endif