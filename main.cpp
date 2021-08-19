#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include "cpp_socket.cpp"

using namespace std;

int main(int argv, char** argc){
    int server_fd, new_socket;
    long valread;
    struct sockaddr_in address;

    char* message = "Hello World!";
    
    SOCKET_WRAPPER::cpp_socket socket_fd = SOCKET_WRAPPER::cpp_socket(AF_INET, SOCK_STREAM, 0, 0, 0); 
    
    while(true){
    
    
    }

    return 0;
}
