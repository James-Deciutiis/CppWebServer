#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <fstream>
#include <iostream>

namespace util{
        enum valid_pages{
            index,
            cat_1,
            dne,
        };
        enum asset_type{
            image,
            html,
            text,
        };

        class response{
            private:
                asset_type type;
                valid_pages page;
                std::string extension;
                std::string transmission;
                std::string file_path;

            public:
                response(std::string request_buffer);
                valid_pages string_code(std::string page);
                char* respond(std::string fp);
                std::string parseForPath(char* buffer);            
                std::string route(std::string request);
        };
}

#endif

