//
//  InvalidCharactersException.cpp
//  StackCalculator
//
//  Created by Arman Tarkhanian on 7/13/16.
//  Copyright © 2016 Arman Tarkhanian. All rights reserved.
//

#include "InvalidCharactersException.h"

namespace cs20a{
   InvalidCharactersException::InvalidCharactersException(const std::string& msg): std::logic_error (msg.c_str()){
        
    }
}