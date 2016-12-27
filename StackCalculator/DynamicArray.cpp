#include "DynamicArray.h"
namespace cs20a
{
    template<class T>
    DynamicArray<T>::DynamicArray(): size(0), capacity(0), darray(new T[0])
    {}
    
    template<class T>
    DynamicArray<T>::DynamicArray(int capacity): size(0), capacity(capacity), darray(new T[capacity])
    {}
    
    template<class T>
    DynamicArray<T>::DynamicArray(const DynamicArray<T> &rhs)
    {
        deepCopy(rhs);
    }
    
    template<class T>
    DynamicArray<T>::~DynamicArray()
    {
        delete[] darray;
    }
    
    template<class T>
    void DynamicArray<T>::add(const T value)
    {
        if (adjustCapacity())
            setCapacity(size + 1);
        
        darray[size++] = value;
    }
    
    template<class T>
    void DynamicArray<T>::removeAt(int index)
    {
        if (index < 0)
            throw("Index must be positive.");
        
        if (index >(size - 1))
            throw("Index must be less than array size.");
        
        for (int i = index; i < (size - 1); i++)
            darray[i] = darray[i + 1];
        
        size--;
        
        if (adjustCapacity())
            setCapacity(size + 1);
    }
    
    template<class T>
    void DynamicArray<T>::insert(int index, T value)
    {
        if (index < 0)
            throw("Index must be positive.");
        
        if (index >(size - 1))
            throw("Index must be less than array size.");
        
        if (adjustCapacity())
            setCapacity(size + 1);
        
        for (int i = size; i > index; i--)
            darray[i] = darray[i - 1];
        
        darray[index] = value;
        size++;
    }
    
    template<class T>
    bool DynamicArray<T>::remove(T value)
    {
        int i = indexOf(value);
        
        if (i >= 0) {
            removeAt(i);
            return true;
        }
        
        return false;
    }
    
    template<class T>
    int DynamicArray<T>::indexOf(const T value) const
    {
        for (int i = 0; i < size; i++)
        {
            if (darray[i] == value)
                return i;
        }
        
        return -1;
    }
    
    template<class T>
    bool DynamicArray<T>::contains(const T value) const
    {
        return indexOf(value) > -1;
    }
    
    template<class T>
    void DynamicArray<T>::clear()
    {
        delete[] darray;
        
        capacity = 0;
        size = 0;
        darray = new T[0];
    }
    
    template<class T>
    int DynamicArray<T>::getSize() const
    {
        return size;
    }
    
    template<class T>
    int DynamicArray<T>::getCapacity() const
    {
        return capacity;
    }
    
    template <class T>
    DynamicArray<T>& DynamicArray<T>::operator =(const DynamicArray<T>& rhs) {
        if (this != &rhs) {
            delete[] darray;
            deepCopy(rhs);
        }
        return(*this);
    }
    
    template<class T>
    T &DynamicArray<T>::operator[](int index) const
    {
        if (index > (size - 1))
            throw("Index must be less than array size.");
        
        return darray[index];
    }
    
    template<class T>
    bool DynamicArray<T>::operator==(DynamicArray<T> & a) const
    {
        if (a.size != size)
            return false;
        
        for (int i = 0; i < size; i++) {
            if (a[i] != darray[i])
                return false;
        }
        
        return true;
    }
    
    template<class T>
    bool DynamicArray<T>::operator!=(DynamicArray<T>& a) const
    {
        return !(*this == a);
    }
    
    template<class T>
    void DynamicArray<T>::deepCopy(const DynamicArray<T>& rhs)
    {
        size = rhs.size;
        capacity = rhs.capacity;
        darray = new T[capacity];
        
        for (int i = 0; i < size; i++)
            darray[i] = rhs.darray[i];
    }
    
    template<class T>
    bool DynamicArray<T>::adjustCapacity() const
    {
        return !((size + 1) > 0.25*capacity && size < capacity);
    }
    
    template<class T>
    void DynamicArray<T>::setCapacity(int minCapacity)
    {
        if (minCapacity < size)
            throw("Capacity must be greater than current size.");
        
        if (minCapacity >= 0)
        {
            int limit = 1;
            while (limit <= minCapacity)
                limit *= 2;
            
            T *tarray = new T[limit];
            
            for (int i = 0; i < size; i++)
                tarray[i] = darray[i];
            
            delete[] darray;
            
            darray = tarray;
            capacity = limit;
        }
    }
}