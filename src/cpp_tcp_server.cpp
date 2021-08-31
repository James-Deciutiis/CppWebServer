#include <stdio.h>
#include <string>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fstream>
#include <iostream>
#include "cpp_socket.cpp"

#define PORT 8080
int main(int argv, char** argc){
    int new_socket;
    long valread;
    struct sockaddr_in address;
    int address_len = sizeof(address);

    SOCKET_WRAPPER::cpp_socket sever_fd(AF_INET, SOCK_STREAM, 0, PORT, INADDR_ANY); 

    while(true){
        std::cout << "\n<----------WAITING FOR A NEW CONNECTION---------->\n" << std::endl;         

        new_socket = sever_fd.accept_socket(sever_fd.getSock(), (struct sockaddr*) &address, (socklen_t *) &address_len);

        char request_buffer[30000] = {0};
        valread = sever_fd.read_socket(new_socket, request_buffer, 30000);
        std::cout << "Message: " << request_buffer << std::endl;

        std::cout << "**Message Sent!**" << std::endl;

        sever_fd.close_socket(new_socket);
    }

    return 0;
}

