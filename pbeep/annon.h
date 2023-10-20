#include "slp-beep.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
/*
for some reason it wont write the html to the screen 


*/
void handle_client(int client_socket) {
    char response[] = "HTTP/1.1 200 OK\r\n"
                     "Content-Type: text/html\r\n\r\n"
                     "<html><body><h1>Hello, World!</h1></body></html>\r\n";
    
    ssize_t bytes_sent = send(client_socket, response, sizeof(response) - 1, 0);
    if (bytes_sent == -1) {
        perror("Error sending response");
    } else {
        printf("Sent %zd bytes\n", bytes_sent);
    }

    close(client_socket);
}

int start_webserver(int port) {
    int server_socket;
    struct sockaddr_in server_addr;

   
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Error creating socket");
        return -1;
    }

    
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr) ) == -1) {
        perror("Error binding to port");
        return -1;
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) == -1) {
        perror("Error listening for connections");
        return -1;
    }

    printf("Server listening on port %d\n", port);

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_size = sizeof(client_addr);
        int client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_size);
        
        if (client_socket == -1) {
            perror("Error accepting connection");
            continue;
        }

        handle_client(client_socket);
    }

    close(server_socket);

    return 0;
}
