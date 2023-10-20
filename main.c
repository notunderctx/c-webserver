#include "pbeep/annon.h"

int main() {
    int port = 8080;

    if (start_webserver(port) == 0) {
        printf("Web server started on port %d\n", port);
    } else {
        printf("Failed to start the web server\n");
    }

    return 0;
}
