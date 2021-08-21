#ifndef CPP_SOCKET_H
#define CPP_SOCKET_H

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>

namespace SOCKET_WRAPPER{
    class cpp_socket{
        private:
            struct sockaddr_in address;
            int connection;
            int sock;
            int listening;

        public:
            cpp_socket(int domain, int service, int protocol, int port, u_long interface);
            void test_connection(int);
            int accept(int socket, const struct sockaddr *address, socklen_t address_len);
            int bind_socket(int socket, const struct sockaddr *address);
            int connect_socket(int socket, const struct sockaddr *address); 
            int listen(int socket, int backlog);
            int getConnection();
            int getSock();
            struct sockaddr_in getAddress();
    };
}

#endif
