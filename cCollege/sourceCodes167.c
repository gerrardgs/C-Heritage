#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_FILES 3

int main() {
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("Pipe creation failed");
        return 1;
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) {
        // Child process: Get and print the current working directory
        close(pipefd[0]); // Close the reading end of the pipe in the child process
        char current_directory[256];
        if (getcwd(current_directory, sizeof(current_directory)) != NULL) {
            printf("Current Working Directory: %s\n", current_directory);
            fflush(stdout);
            write(pipefd[1], current_directory, sizeof(current_directory)); // Write the directory path to the pipe
        }
        close(pipefd[1]); // Close the writing end of the pipe in the child process
        exit(0);
    } else {
        // Parent process: Wait for the child process to complete
        wait(NULL);
        close(pipefd[1]); // Close the writing end of the pipe in the parent process

        // Read the directory path from the pipe
        char current_directory[256];
        read(pipefd[0], current_directory, sizeof(current_directory));

        printf("\nFiles in the directory:\n");

        DIR *dir;
        struct dirent *entry;
        int file_count = 0;

        dir = opendir(current_directory);
        if (dir == NULL) {
            perror("Unable to open directory");
            return 1;
        }

        // Read and print the first 3 files in the directory
        while ((entry = readdir(dir)) != NULL && file_count < MAX_FILES) {
            if (entry->d_type == DT_REG) { // Check if it's a regular file
                printf("%s\n", entry->d_name);
                file_count++;
            }
        }

        closedir(dir);
        close(pipefd[0]); // Close the reading end of the pipe in the parent process
    }

    return 0;
}
