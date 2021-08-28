#ifndef CPP_SOCKET_H
#define CPP_SOCKET_H

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <iostream>
#include <string.h>

namespace SOCKET_WRAPPER{
    class cpp_socket{
        private:
            struct sockaddr_in address;
            int connection;
            int sock;
            int listening;

        public:
            cpp_socket(int domain, int service, int protocol, int port, u_long interface);
            int accept_socket(int socket, struct sockaddr *address, socklen_t *address_len);
            int bind_socket(int socket, const struct sockaddr *address, int size);
            int connect_socket(int socket, const struct sockaddr *address); 
            int socket_listen(int socket, int backlog);
            int getConnection();
            int getSock();
            void test_connection(int);
            void write_socket(int socket, char* message, int size);
            void close_socket(int socket);
            long read_socket(int socket, char* buffer, int size);
            struct sockaddr_in getAddress();
    };
}

#endif
