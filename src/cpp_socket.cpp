#include "cpp_socket.h"
namespace SOCKET_WRAPPER{
    cpp_socket::cpp_socket(int domain, int service, int protocol, int port, u_long interface){
        address.sin_family = domain;
        address.sin_port = htons(port);
        address.sin_addr.s_addr = htonl(interface); 
        
        sock = socket(domain, service, protocol);
        test_connection(sock);
        std::cout<<"Socket Created"<<std::endl;


        memset(address.sin_zero, '\0', sizeof(address.sin_zero));

        connection = bind_socket(sock, (struct sockaddr*) &address, sizeof(address));
        std::cout<<"Socket Connection Established"<<std::endl;
        test_connection(connection);

        //Magic numbers are not good... I will change this later.
        listening = socket_listen(sock, 10);
        std::cout<<"Socket Listening on Port: "<<port<<std::endl;
        test_connection(listening);
    }

    int cpp_socket::bind_socket(int socket, const struct sockaddr *address, int size){
        return bind(socket, address, size);
    }
                
    int cpp_socket::connect_socket(int socket, const struct sockaddr *address){
        return connect(socket, address, sizeof(address));
    }

    int cpp_socket::socket_listen(int socket, int backlog){
        return listen(socket, backlog);
    }

    int cpp_socket::accept_socket(int socket, struct sockaddr *__restrict add, socklen_t *__restrict add_len){
        int retval = accept(socket, add, add_len);
        test_connection(retval);
        return retval;
    }

    int cpp_socket::getConnection(){
        return connection;
    }

    int cpp_socket::getSock(){
        return sock;
    }

    void cpp_socket::test_connection(int test){
        if(test < 0){
            perror("Failed to connect.");
            exit(EXIT_FAILURE);
        }
    }

    void cpp_socket::write_socket(int socket, char *message, int size){
        write(socket, message, size);
    }

    void cpp_socket::close_socket(int socket){
        close(socket);
    }

    long cpp_socket::read_socket(int socket, char* buffer, int size){
        return read(socket, buffer, size);
    }

    struct sockaddr_in cpp_socket::getAddress(){
        return address;
    }
}

