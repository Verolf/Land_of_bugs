#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    char *error = "ERROR", * http = "http://";
    char str[150], url[150];
    int i = 0, k = 0;
    scanf("%c", &str[i]);
    while (str[i] != NULL) {
        while (str[i] != '\n') {
            i++;
            scanf("%c", &str[i]);
        }
        
        if (strstr(str, error) != NULL) {
            if (strstr(str, http) != NULL) {
                strcpy(url, strstr(str, http));
                printf("%s", url);
            }
        }
        
        
        i = 0;        
        for (i = 0; i < 150; i++) {
            str[i] = NULL;
        }
        
        i = 0;
        scanf("%c", &str[i]);
    }
    return 0;
}
