/* c_tcp_nodelay_client.c
 * Simple TCP client demonstrating TCP_NODELAY
 * Compile: gcc -o c_tcp_nodelay_client c_tcp_nodelay_client.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>
#include <sys/socket.h>

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) { perror("socket"); return 1; }

    int one = 1;
    if (setsockopt(sock, IPPROTO_TCP, TCP_NODELAY, &one, sizeof(one)) < 0) {
        perror("setsockopt TCP_NODELAY");
    } else {
        printf("TCP_NODELAY enabled\n");
    }

    struct sockaddr_in srv = {0};
    srv.sin_family = AF_INET;
    srv.sin_port = htons(9000);
    inet_pton(AF_INET, "127.0.0.1", &srv.sin_addr);

    if (connect(sock, (struct sockaddr*)&srv, sizeof(srv)) < 0) {
        perror("connect");
        close(sock);
        return 1;
    }

    send(sock, "hello\n", 6, 0);
    sleep(1);
    close(sock);
    return 0;
}
