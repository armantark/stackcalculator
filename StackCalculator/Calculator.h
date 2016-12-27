//
//  Calculator.h
//  StackCalculator
//
//  Created by Arman Tarkhanian on 7/6/16.
//  Copyright © 2016 Arman Tarkhanian. All rights reserved.
//

#ifndef Calculator_h
#define Calculator_h

#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

namespace cs20a{
    class Calculator{
    public:
        static double evaluate(const string infix);
        static string infixToPostfix(const string infix);
        static double evaluatePostfix(const string postfix);
        
        static bool checkDelimiters(const string infix);
        static bool checkValidChars(const string infix);
    private:
        static bool isOperand(char ch);
        static bool isOperator(char ch);
        static bool isValidChar(char ch);
        
        static int weight(char ch);
    };
}
#endif /* Calculator_h */
