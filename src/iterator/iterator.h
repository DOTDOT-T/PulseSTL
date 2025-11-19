#ifndef PULSE_STL_ITERATOR_H
#define PULSE_STL_ITERATOR_H

namespace PulseLibs::STL
{
    /**
     * @brief Simple iterator structure to use with all PSTL containers
     * 
     * @tparam Object Type of object the iterator refers to
     */
    template<typename Object>
    struct Iterator
    {
        using reference = Object&;
        using pointer   = Object*;

        pointer ptr;

        reference operator*() const { return *ptr; }
        pointer   operator->() const { return ptr; }

        Iterator& operator++() { ++ptr; return *this; }     // prefix
        Iterator  operator++(int) { Iterator tmp = *this; ++ptr; return tmp; } // postfix

        Iterator& operator--() { --ptr; return *this; }     // prefix decrement
        Iterator  operator--(int) { Iterator tmp = *this; --ptr; return tmp; } // postfix decrement

        bool operator==(const Iterator& other) const { return ptr == other.ptr; }
        bool operator!=(const Iterator& other) const { return ptr != other.ptr; }
    };

    /**
     * @brief Reverse iterator that works in the opposite direction of a normal iterator
     * 
     * @tparam Object Type of object the iterator refers to
     */
    template<typename Object>
    struct ReverseIterator
    {
        using reference = Object&;
        using pointer   = Object*;

        Iterator<Object> base; // base iterator pointing after the element

        reference operator*() const
        {
            Iterator<Object> tmp = base;
            --tmp.ptr;
            return *tmp;
        }

        pointer operator->() const
        {
            return &(**this);
        }

        ReverseIterator& operator++() { --base.ptr; return *this; }      // prefix
        ReverseIterator  operator++(int) { ReverseIterator tmp = *this; --base.ptr; return tmp; } // postfix

        ReverseIterator& operator--() { ++base.ptr; return *this; }      // prefix decrement
        ReverseIterator  operator--(int) { ReverseIterator tmp = *this; ++base.ptr; return tmp; } // postfix decrement

        bool operator==(const ReverseIterator& other) const { return base.operator==(other.base); }
        bool operator!=(const ReverseIterator& other) const { return base.operator!=(other.base); }
    };
};

#endif
