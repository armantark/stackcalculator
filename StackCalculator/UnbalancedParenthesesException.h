//
//  UnbalancedParenthesesException.h
//  StackCalculator
//
//  Created by Arman Tarkhanian on 7/13/16.
//  Copyright © 2016 Arman Tarkhanian. All rights reserved.
//

#ifndef UnbalancedParenthesesException_h
#define UnbalancedParenthesesException_h

#include <iostream>
#include <exception>

namespace cs20a{
    class UnbalancedParenthesesException: public std::logic_error{
    public:
        UnbalancedParenthesesException(const std::string& msg);
    };
}

#endif /* UnbalancedParenthesesException_h */
