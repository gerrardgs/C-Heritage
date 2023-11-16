// server

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_PORT 8080
#define MAX_BUFFER_SIZE 1024
#define MAX_NUMBERS 100

int numbers[MAX_NUMBERS];
int num_count = 0;

void handle_post(int new_socket, char *buffer) {
    int num;
    if (sscanf(buffer, "POST %d", &num) == 1) {
        if (num_count < MAX_NUMBERS) {
            numbers[num_count++] = num;
            send(new_socket, "Penambahan angka berhasil\n", strlen("Penambahan angka berhasil\n"), 0);
        } else {
            send(new_socket, "Server penuh\n", strlen("Server penuh\n"), 0);
        }
    } else {
        send(new_socket, "Bad request\n", strlen("Bad request\n"), 0);
    }
}

void handle_get(int new_socket) {
    char response[MAX_BUFFER_SIZE];
    memset(response, 0, sizeof(response));
    char temp[MAX_BUFFER_SIZE];
    for (int i = 0; i < num_count; i++) {
        snprintf(temp, sizeof(temp), "%d ", numbers[i]);
        strcat(response, temp);
    }
    strcat(response, "\n");
    send(new_socket, response, strlen(response), 0);
}

int main() {
    int server_socket, new_socket;
    struct sockaddr_in server_addr;
    int opt = 1;
    int addrlen = sizeof(server_addr);
    char buffer[MAX_BUFFER_SIZE] = {0};

    // Create socket file descriptor
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Attach socket to the given port
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);

    // Bind the socket to the specified port
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", SERVER_PORT);

    while (1) {
        // Accept a new connection
        if ((new_socket = accept(server_socket, (struct sockaddr *)&server_addr, (socklen_t *)&addrlen)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        // Read the client command
        int valread = read(new_socket, buffer, MAX_BUFFER_SIZE);

        if (valread > 0) {
            // Handle the client command
            if (strncmp(buffer, "POST", 4) == 0) {
                handle_post(new_socket, buffer);
            } else if (strncmp(buffer, "GET", 3) == 0) {
                handle_get(new_socket);
            } else {
                send(new_socket, "Bad request\n", strlen("Bad request\n"), 0);
            }
        }

        close(new_socket);
    }

    return 0;
}
