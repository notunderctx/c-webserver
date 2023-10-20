# W E B S E R V E R    IN  C

to make a webserver write the following in the main.c
```c
#include "pbeep/annon.h" 

int main() {
    int port = 8080; //define a port.to visit the site type http://localhost:8080/

    if (start_webserver(port) == 0) {
        printf("Web server started on port %d\n", port);
    } else {
        printf("Failed to start the web server\n");
    }

    return 0;
}


```