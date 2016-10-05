#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char ** argv, char ** envp) {
    int i;
    char *user[20];
    scanf("%s\n", user);
    for (i = 0; envp[i] != NULL; i++) {
        if (strstr(envp[i], user) != NULL) {
            printf("%s\n", envp[i]);
        }     
    }
    return 0;
}
