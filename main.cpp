#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include "cpp_socket.cpp"

int main(int argv, char** argc){
    int server_fd, new_socket;
    long valread;
    struct sockaddr_in address;
    int address_len = sizeof(address);

    char* message = "Hello World!";
    
    SOCKET_WRAPPER::cpp_socket socket_fd = SOCKET_WRAPPER::cpp_socket(AF_INET, SOCK_STREAM, 0, 0, 0); 
    
    while(true){
        std::cout<<"\n<----------WAITING FOR A NEW CONNECTION---------->\n"<<std::endl;         

        new_socket = socket_fd.accept(server_fd, (struct sockaddr*) &address, address_len);

        char buffer[30000] = {0};
        
    
    }

    return 0;
}
