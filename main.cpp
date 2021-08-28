#include <stdio.h>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include "cpp_socket.cpp"

#define PORT 8080
int main(int argv, char** argc){
    int server_fd, new_socket;
    long valread;
    struct sockaddr_in address;
    int address_len = sizeof(address);

    std::string message = "Hello World!";
    
    SOCKET_WRAPPER::cpp_socket socket_fd(AF_INET, SOCK_STREAM, 0, PORT, INADDR_ANY); 
    while(true){
        std::cout<<"\n<----------WAITING FOR A NEW CONNECTION---------->\n"<<std::endl;         

        new_socket = socket_fd.accept_socket(socket_fd.getSock(), (struct sockaddr*) &address, (socklen_t *) &address_len);

        char buffer[30000] = {0};
        valread = socket_fd.read_socket(socket_fd.getSock(), buffer, 30000);
        std::cout<< "Message: " << buffer << std::endl;

        socket_fd.write_socket(socket_fd.getSock(), (char *) &message, sizeof(&message));
        std::cout<< "Message Sent!" << std::endl;

        socket_fd.close_socket(socket_fd.getSock());
    }

    return 0;
}
