#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char* find_command_path(const char* command) {
    char* path_env = getenv("PATH");
    if (path_env == NULL) {
        return NULL;
    }

    char* path_copy = strdup(path_env);
    char* path = strtok(path_copy, ":");
    while (path != NULL) {
        char full_path[4096];
       snprintf(full_path, sizeof(full_path), "%s/%s", path, command);
        if (access(full_path, X_OK) == 0) {
            free(path_copy);
            return strdup(full_path);
        }
        path = strtok(NULL, ":");
    }
    free(path_copy);
    return NULL;
}

int run_command(const char* command) {
    char* path = find_command_path(command);
    if (path == NULL) {
        printf("Command not found: %s\n", command);
        return 1;
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        free(path);
        return 1;
    }
    if (pid == 0) {
        // Child process
        execl(path, command, NULL);
        // If execl returns, it means there was an error
        perror("execl");
        exit(1);
    }
    // Parent process
    int status;
    waitpid(pid, &status, 0);
    free(path);
    return WEXITSTATUS(status);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <command>\n", argv[0]);
        return 1;
    }
    return run_command(argv[1]);
}
