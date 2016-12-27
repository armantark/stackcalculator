#ifndef Stack_h
#define Stack_h

#include <iostream>
#include "DynamicArray.h"
using namespace std;

namespace cs20a {
    template <class T>
    class Stack {
        
    public:
        Stack(); //Initializes the stack with a 0
        Stack(int capacity); //Initializes the stack with a capacity
        
        void push(const T value); //Adds a value at the end
        T pop(); //Takes the value off the end and returns the value
        T peek() const; //shows the value at the end
        
        void clear(); //Deletes all values
        
        int getSize() const; //Gets the current number of values inside the stack
        
        bool isEmpty() const; //Returns true if empty, false if not
        
        bool operator==(Stack<T> & a) const; //Checks if one stack is equal to the other
        bool operator!=(Stack<T> & a) const; //Checks if one stack isn't equal to the other
        
        template<class U> friend ostream& operator<< (ostream& outs,  Stack<U>& rhs); //Outputs the values of the stack
        
    private:
        DynamicArray<T> stack;
        
    };
}
#endif /* Stack_h */
