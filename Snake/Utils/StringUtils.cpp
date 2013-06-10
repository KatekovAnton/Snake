//
//  StringUtils.cpp
//  MAX
//
//  Created by  Developer on 16.02.13.
//  Copyright (c) 2013 AntonKatekov. All rights reserved.
//

#include "StringUtils.h"
#include "miniPrefix.h"

std::string intToString(int value)
{
    std::basic_stringstream<char> ss;
    ss<<value;
    std::string str;
    ss>>str;
    return str;
}
