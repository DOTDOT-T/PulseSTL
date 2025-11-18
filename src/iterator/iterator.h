#ifndef PULSE_STL_ITERATOR_H
#define PULSE_STL_ITERATOR_H

namespace PulseLibs::STL
{
    template<typename Object>
    struct Iterator
    {
        Object* ptr;

        Iterator(Object* ptrIte)
        {
            ptr = ptrIte;
        }

        Object& operator*() const { return *ptr; }
        Object* operator->() const { return ptr; }
    };
};

#endif