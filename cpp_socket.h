#ifndef CPP_SOCKET_H
#define CPP_SOCKET_H


#include <stdio.h>
#include <sys/socket.h>

namespace SOCKET_CONTAINER{
    class cpp_socket{
        private:
            int connection;

        public:
            cpp_socket(int domain, int service, int protocol);
            int bind_socket(int socket, const struct sockaddr *address, socklen_t address_len);
    
    };
}

#endif
