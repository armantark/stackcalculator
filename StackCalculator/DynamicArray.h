#ifndef DynamicArray_h
#define DynamicArray_h

#include <iostream>
namespace cs20a
{
    template<class T>
    class DynamicArray
    {
    public:
        DynamicArray();
        DynamicArray(int capacity);
        DynamicArray(const DynamicArray<T> &rhs);
        
        ~DynamicArray();
        
        void add(const T value);
        void removeAt(int index);
        void insert(int index, T value);
        bool remove(const T value);
        
        int indexOf(const T value) const;
        bool contains(const T value) const;
        
        void clear();
        
        int getSize() const;
        int getCapacity() const;
        
        DynamicArray<T>& operator =(const DynamicArray<T>& rhs);
        
        T &operator[](int index) const;
        
        bool operator==(DynamicArray<T> & a) const;
        bool operator!=(DynamicArray<T> & a) const;
        
    private:
        int size;
        int capacity;
        T *darray;
        
        void deepCopy(const DynamicArray<T>& rhs);
        void setCapacity(int newCapacity);
        bool adjustCapacity() const;
        
    };
}
#endif /* DynamicArray_h */
