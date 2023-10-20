#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <stdio.h>

void handle_client(int client_socket);


int start_webserver(int port);

#endif // WEBSERVER_H