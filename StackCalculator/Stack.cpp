#include "Stack.h"

namespace cs20a
{
    template<class T>
    Stack<T>::Stack(): stack(0)
    {}
    
    template<class T>
    Stack<T>::Stack(int capacity): stack(capacity)
    {}
    
    template <class T>
    void Stack<T>::push(const T value)
    {
        stack.add(value);
    }
    
    template <class T>
    T Stack<T>::peek() const
    {
        if (isEmpty())
            throw string("Stack is empty.");
        return stack[stack.getSize() - 1];
    }
    
    template <class T>
    T Stack<T>::pop()
    {
        if (isEmpty())
            throw string("Stack is empty.");
        T element = peek();
        stack.removeAt(stack.getSize() - 1);
        
        return element;
    }
    
    template <class T>
    bool Stack<T>::isEmpty() const
    {
        return (stack.getSize() == 0);
    }
    
    template <class T>
    ostream& operator<< (ostream& outs, Stack<T>& rhs)
    {
        for (int i = rhs.getSize() - 1; i >= 0; i--)
            outs << rhs.stack[i] << endl;
        
        return(outs);
    }
    
    template<class T>
    int Stack<T>::getSize() const
    {
        return stack.getSize();
    }
    
    template<class T>
    bool Stack<T>::operator==(Stack<T> & a) const
    {
        return stack == a.stack;
    }
    
    template<class T>
    bool Stack<T>::operator!=(Stack<T>& a) const
    {
        return stack != a.stack;
    }
    
    template<class T>
    void Stack<T>::clear()
    {
        stack.clear();
    }
}