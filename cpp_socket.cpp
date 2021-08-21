#include "cpp_socket.h"

SOCKET_WRAPPER::cpp_socket::cpp_socket(int domain, int service, int protocol, int port, u_long interface){
    address.sin_family = domain;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = htonl(interface); 
    
    sock = socket(domain, service, protocol);
    test_connection(sock);

    connection = connect_socket(domain, (struct sockaddr*) &address);
    test_connection(connection);

    //Magic numbers are not good... I will change this later.
    listening = listen(sock, 10);
    test_connection(listening);
}

int SOCKET_WRAPPER::cpp_socket::bind_socket(int socket, const struct sockaddr *address){
    return bind(socket, address, sizeof(address));
}
            
int SOCKET_WRAPPER::cpp_socket::connect_socket(int socket, const struct sockaddr *address){
    return connect(socket, address, sizeof(address));
}

int SOCKET_WRAPPER::cpp_socket::listen(int socket, int backlog){
    return listen(socket, backlog);
}

void SOCKET_WRAPPER::cpp_socket::test_connection(int test){
    if(test < 0){
        perror("Failed to connect.");
        exit(EXIT_FAILURE);
    }
}

int SOCKET_WRAPPER::cpp_socket::accept(int socket, const struct sockaddr *address, socklen_t address_len){
    int retval = accept(socket, (struct sockaddr *)&address, address_len);
    test_connection(retval);
    return retval;
}

int SOCKET_WRAPPER::cpp_socket::getConnection(){
    return connection;
}

int SOCKET_WRAPPER::cpp_socket::getSock(){
    return sock;
}

struct sockaddr_in SOCKET_WRAPPER::cpp_socket::getAddress(){
    return address;
}
