#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include <fstream>
#include <iostream>

namespace utililities{
        enum valid_pages{
            index,
            dne,
        };

        valid_pages string_code(std::string page);
        char* reponse(std::string fp);
        std::string parseForPath(char* buffer);            
        std::string route(std::string request);
}

#endif

