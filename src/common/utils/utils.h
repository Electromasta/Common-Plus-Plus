#pragma once
#include "common/core.types.h"

namespace Common  {
    inline bool isNum(const String & s)    {
        String::const_iterator it = s.begin();
        while (it != s.end() && std::isdigit(*it)) ++it;
        return !s.empty() && it == s.end();
    }

    inline String trim(const String & str) {
        size_t start = str.find_first_not_of(" \t\n\r\f\v");
        size_t end = str.find_last_not_of(" \t\n\r\f\v");
        
        if (start == String::npos) return "";
        return str.substr(start, end - start + 1);
    }
}