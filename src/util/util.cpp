#include "util.h"

namespace util{
    response::response(std::string request_buffer){
        file_path = parseForPath(request_buffer);
        type = util::asset_type::image;
    }

    valid_pages response::string_code(std::string page){
        if(page == "/" || page == "/index"){
            return valid_pages::index;
        }
        if(page == "/cat-1"){
            return valid_pages::cat_1;
        }

        return valid_pages::dne;
    }
    
    char* response::respond(std::string fp){
        if(fp == "dne"){
            std::string error("HTTP/1.1 404 PAGE NOT FOUND\n");
            return &error[0];
        }

        std::ifstream file(fp);
        std::string line;
        std::string file_transmission;
        if(file.is_open()){
            while(getline(file, line)){
                file_transmission+=line;
            }
        }

        int transmission_length = strlen((char *) &file_transmission[0]) + 100;

        std::string header("HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: ");
        std::string message_string = header + std::to_string(transmission_length)+ "\n\n" + file_transmission;

        char* message = new char[transmission_length + 1];
        strcpy(message, &message_string[0]);

        return message;
    }

    std::string response::parseForPath(char* buffer){
        std::string retval;
        std::string str(buffer); 
        bool inpath = false;
        for(auto& c : str){
            if(c == '/'){
               inpath = true; 
            }
            if(inpath && c != ' '){
                retval += c;
            }
            if(inpath && c == ' '){
                return retval;
            }
        }
        return retval;
    }

    std::string response::route(std::string request){
        switch(string_code(request)){
            case valid_pages::index:
                return "../../assets/pages/index.html";
            case valid_pages::cat_1:
                return "../../assets/images/cat-1.jpg";;
            default:
                return "dne";
        }
    }
}

