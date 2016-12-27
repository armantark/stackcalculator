//
//  DivideByZeroException.h
//  StackCalculator
//
//  Created by Arman Tarkhanian on 7/13/16.
//  Copyright © 2016 Arman Tarkhanian. All rights reserved.
//

#ifndef DivideByZeroException_h
#define DivideByZeroException_h

#include <iostream>
#include <exception>

namespace cs20a{
    class DivideByZeroException: public std::logic_error{
    public:
        DivideByZeroException(const std::string& msg);
    };
}

#endif /* DivideByZeroException_h */
