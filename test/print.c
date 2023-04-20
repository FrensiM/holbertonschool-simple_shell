#include <stdio.h>
#include <stdlib.h>

int main() 
{
    char *line = NULL;
    size_t len = 0;
    printf("$ ");
    ssize_t read = getline(&line, &len, stdin);
    while (read != -1) {
        printf("%s$ ", line);
        free(line);
        line = NULL;
        read = getline(&line, &len, stdin);
    }
    free(line);
    return 0;
}
