#include "utilities.h"

namespace utililities{
    valid_pages string_code(std::string page){
        if(page == "/" || page == "/index"){
            return valid_pages::index;
        }

        return valid_pages::dne;
    }
    
    char* reponse(std::string fp){
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

        std::string message_string("HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: ");
        message_string+=std::to_string(transmission_length)+"\n\n";
        message_string+=file_transmission;

        char* message = new char[transmission_length + 1];
        strcpy(message, &message_string[0]);

        return message;
    }

    std::string parseForPath(char* buffer){
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
                break;
            }
        }
        return retval;
    }

    std::string route(std::string request){
        switch(string_code(request)){
            case valid_pages::index:
                return "./pages/index.html";
            default:
                return "dne";
        }
    }
}

