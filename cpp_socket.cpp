#include "cpp_socket.h"

SOCKET_CONTAINER::cpp_socket::cpp_socket(int domain, int service, int protocol){
    connection = socket(domain, service, protocol);
}

int SOCKET_CONTAINER::cpp_socket::bind_socket(int socket, const struct sockaddr *address, socklen_t address_len){
    return 0;
}
