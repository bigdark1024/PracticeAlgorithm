#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    char str[] = "A bird came down the walk";
    const char *delim = " ";
    char *next_token;
    char* token = NULL;

    printf("Parsing the input string '%s'\n", str);
    token = strtok_s(str, delim, &next_token);
    while(token) {
        printf("%s\n", token);
        token = strtok_s(NULL, delim, &next_token);
    }
    return 0;
}


