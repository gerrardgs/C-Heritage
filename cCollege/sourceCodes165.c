//client

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_PORT 8080
#define MAX_BUFFER_SIZE 1024

int main() {
    int client_socket;
    struct sockaddr_in server_addr;
    char buffer[MAX_BUFFER_SIZE] = {0};

    // Create socket file descriptor
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
        perror("Invalid address or address not supported");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // Get user input and send it to the server
    while (1) {
        printf("Enter command (POST <number> or GET): ");
        fgets(buffer, MAX_BUFFER_SIZE, stdin);
        send(client_socket, buffer, strlen(buffer), 0);

        // Receive and print server response
        int valread = read(client_socket, buffer, MAX_BUFFER_SIZE);
        if (valread > 0) {
            buffer[valread] = '\0';
            printf("%s", buffer);
        }
    }

    return 0;
}
