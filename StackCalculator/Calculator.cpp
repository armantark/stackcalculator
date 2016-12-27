//
//  Calculator.cpp
//  StackCalculator
//
//  Created by Arman Tarkhanian on 7/6/16.
//  Copyright © 2016 Arman Tarkhanian. All rights reserved.
//

#include "Calculator.h"
#include "Stack.cpp"
#include "DynamicArray.cpp"
#include "UnbalancedParenthesesException.h"
#include "DivideByZeroException.h"
#include "InvalidCharactersException.h"
#include <math.h>
#include <string>
#include <sstream>

namespace cs20a{
    double Calculator::evaluate(const string infix){
        return evaluatePostfix(infixToPostfix(infix));
    }
    
    string Calculator::infixToPostfix(const string infix){
        Stack<char> infixToPostfixStack;
        string postfix = "";
        checkValidChars(infix);
        checkDelimiters(infix);
        for(int i = 0; i < infix.size(); i++){
            if (isOperand(infix[i])){
                postfix += infix[i];
            }
            else if (infix[i] == '('){
                infixToPostfixStack.push(infix[i]);
            }
            else if (isOperator(infix[i])){
                //while stack is not empty, and the top of the stack is either an operator with precedence >= token or not a ‘(‘
                while (!infixToPostfixStack.isEmpty() && (isOperator(infixToPostfixStack.peek()) && weight(infixToPostfixStack.peek()) >= weight(infix[i]) && infixToPostfixStack.peek() != '(')){
                    postfix += " ";
                    postfix += (infixToPostfixStack.pop());
                }
                postfix += ' ';
                infixToPostfixStack.push(infix[i]);
            }
            else if (infix[i] == ')'){
                while (!infixToPostfixStack.isEmpty() && infixToPostfixStack.peek() != '('){
                    postfix += ' ';
                    postfix += (infixToPostfixStack.pop());
                }
                if (infixToPostfixStack.peek() == '('){
                    infixToPostfixStack.pop();
                }
            }
        }
        
        while (!infixToPostfixStack.isEmpty()){
            postfix += ' ';
            postfix += (infixToPostfixStack.pop());
        }
        return postfix;
    }
    
    double Calculator::evaluatePostfix(const string postfix){
        Stack<double> evaluateStack;
        stringstream ss(postfix);
        for(int i = 0; i < postfix.size(); i++){
            if(isOperand(postfix[i])){
                //My failed attempt to make a stod function, ignore.
                
                //                double operand = 0;
                //                while(i<postfix.length() && isOperand(postfix[i])) {
                //                    // For a number with more than one digits, as we are scanning from left to right.
                //                    // Everytime we get a digit towards right, we can multiply current total in operand by 10
                //                    // and add the new digit.
                //                    char test = postfix[i]; //remove later
                //                    if (postfix[i] != '.'){
                //                        int operandIterator = 0;
                //                        if ((operand-(int)operand)==0){
                //                            operand = (operand*10) + (postfix[i] - '0');
                //                            i++;
                //                        }
                //                        else{
                //                            operand = operand + (((double)postfix[i+1]-'0')/pow(10,operandIterator));//This would only work if it's the first in the expression, probably make a new iterator that starts at the beginning of the number somehow? EDIT: I tried fixing it, test it later! EDIT: Adds +1 instead of +.01 for some reason.
                //                            i += 2; //Probably not right either
                //                            operandIterator++;
                //                        }
                //                    }
                //                    else if(postfix[i] == '.'){
                //                        operand = operand + (((double)postfix[i+1]-'0')/10);
                //                        i++;
                //                    }
                //                }
                //                i--;
                double operand = 0;
                ss >> operand;
                while (postfix[i] != ' '){
                    i++;
                }
                evaluateStack.push(operand);
            }
            else if (isOperator(postfix[i])){
                ss.ignore(postfix.length(), postfix[i]);
                double operand2 = evaluateStack.pop();
                if (operand2 == 0 && postfix[i] == '/')
                    throw DivideByZeroException("Error: Division by zero!");
                double operand1 = evaluateStack.pop();
                switch (postfix[i])
                {
                    case '+':
                        evaluateStack.push(operand1 + operand2);
                        break;
                    case '-':
                        evaluateStack.push(operand1 - operand2);
                        break;
                    case '*':
                        evaluateStack.push(operand1 * operand2);
                        break;
                    case '/':
                        evaluateStack.push(operand1 / operand2);
                        break;
                }
            }
        }
        return evaluateStack.pop();
    }
    
    bool Calculator::isOperand(char ch){
        switch (ch){
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case '.':
                return true;
                break;
            default:
                return false;
        }
    }
    
    bool Calculator::isOperator(char ch){
        switch (ch){
            case '+':
            case '-':
            case '*':
            case '/':
                return true;
                break;
            default:
                return false;
        }
    }
    
    bool Calculator::isValidChar(char ch){
        // +, -, *, /, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, ‘(‘, ‘)’, ‘ ‘, '.'
        switch (ch){
            case '+':
            case '-':
            case '*':
            case '/':
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case '(':
            case ')':
            case '.':
            case ' ':
                return true;
                break;
            default:
                throw UnbalancedParenthesesException("Error: invalid character");
                return false;
        }
    }
    
    bool Calculator::checkDelimiters(const string infix){
        
        Stack<char> delimitersStack;
        for(int i = 0; i < infix.size(); i++){
            if (infix[i] == '(')
                delimitersStack.push(infix[i]);
            if (infix[i] == ')'){
                if (delimitersStack.isEmpty()){
                    throw UnbalancedParenthesesException("Errror: Unbalanced parentheses!");
                    return false;
                }
                else if (delimitersStack.pop() != '(' || infix[i] != ')'){
                    throw UnbalancedParenthesesException("Errror: Unbalanced parentheses!");
                    return false;
                }
            }
        }
        if (delimitersStack.isEmpty())
            return true;
        else
            return false;
    }
    
    bool Calculator::checkValidChars(const string infix){
        for (int i = 0; i < infix.size(); i++){
            if (!isValidChar(infix[i])){
                throw InvalidCharactersException("Error: Invalid characters!");
                return false;
            }
        }
        return true;
    }
    
    int Calculator::weight(char ch){
        if (ch == '*' || ch == '/')
            return 2;
        
        else if (ch == '+' || ch == '-')
            return 1;
        
        else return 0;
    }
}