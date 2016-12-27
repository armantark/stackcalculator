//
//  main.cpp
//  StackCalculator
//
//  Created by Arman Tarkhanian on 7/5/16.
//  Copyright © 2016 Arman Tarkhanian. All rights reserved.
//

#include <iostream>
#include <string>
#include "DynamicArray.cpp"
#include "Stack.cpp"
#include "Calculator.h"
#include "UnbalancedParenthesesException.h"
#include "DivideByZeroException.h"
#include "InvalidCharactersException.h"

using namespace std;
using namespace cs20a;

int main() {
    string expr[] = {
        "12+(14*10+9)", //161
        "7 * 122 - (100 + 1/2) * 14",//-553
        "50 * 2 * 3 * (6/0)",//Divide by 0
        "((17.2+2.9)*15-12.7)/(7-4.0)",//96.2667
        "5 + ((1 + 2) * 4) - 3",//14
        "12 * (4 + 6)",//120
        "1 + 2)/10",//Missing parenthesis error
        "2.21/6*1.1+(3.145 -1.1)",//2.4501667
        "1 * 2.2 + x"//Invalid character
    };
    cout << endl;
    cout << " " << "Stack Calculator Assignment" << endl << endl;
    int size = sizeof(expr)/sizeof(expr[0]);
    for (int i=0; i < size; i++)
    {
        try
        {
            cout << " " << "Infix Expression: " << expr[i] << endl;
            cout << " " << "Postfix Expression: " <<
            Calculator::infixToPostfix(expr[i]) << endl;
            cout << " " << "Result = " << Calculator::evaluate(expr[i]) << endl;
        }
        catch (exception e)
        {
            cout << " " << expr[i] << ": " << e.what() << endl;
        }
    }
    cout << endl << endl;
    return 0;
    
}