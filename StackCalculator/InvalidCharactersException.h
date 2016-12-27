//
//  InvalidCharactersException.h
//  StackCalculator
//
//  Created by Arman Tarkhanian on 7/13/16.
//  Copyright © 2016 Arman Tarkhanian. All rights reserved.
//

#ifndef InvalidCharactersException_h
#define InvalidCharactersException_h

#include <iostream>
#include <exception>

namespace cs20a{
    class InvalidCharactersException: public std::logic_error{
    public:
        InvalidCharactersException(const std::string& msg);
    };
}

#endif /* InvalidCharactersException_h */
