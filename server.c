#include <stdio.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

static const uint16_t SRV_PORT = 65000;

static const char* STOP_WORD = "STOP";

void fillAddress(struct sockaddr_in *addr, int port);

void *op_connect(void *);

int main() {
    struct sockaddr_in addr;
    fillAddress(&addr, SRV_PORT);

    int sd = socket(AF_INET, SOCK_STREAM, 0);
    if (sd < 0) {
        perror("socket() fail");
        exit(1);
    }

    if (bind(sd, (const struct sockaddr *) &addr, sizeof(addr))) {
        perror("bind() fail");
        close(sd);
        exit(1);
    }

    struct sockaddr_in cliAddr;
    
    if (listen(sd, 5)) {
            perror("listen() fail");
        }
        
    int cliLen = sizeof(cliAddr);
    int cliSd; 
 
 
 
    
    while ((cliSd = accept(sd, (struct sockaddr *) &cliAddr, (socklen_t *) &cliLen))) {
        //puts("connect");
        pthread_t thid;
        if (pthread_create(&thid, (pthread_attr_t *) NULL, op_connect, (void*)&cliSd) < 0) {
            perror("tread is not create\n");
            return 1;
        }       
        //puts("connect is ok");    
    }
    
    close(sd);
    return 0;
}

void *op_connect(void * cliSd) {
    char buf[256];
    int sd = *(int*)cliSd;
    
    if (strncmp(buf, STOP_WORD, strlen(STOP_WORD))) {
        bzero(buf, 256);
        if (read(sd, buf, sizeof(buf)) < 0) {
            perror("read() fail");
        }
        printf("%s->me:\n %s\n", "kek", buf);
    }


    close(sd);
    return 0;
}



void fillAddress(struct sockaddr_in *addr, int port) {
  bzero(addr, sizeof(*addr));
  (*addr).sin_family = AF_INET;
  (*addr).sin_addr.s_addr = INADDR_ANY;
  (*addr).sin_port = htons(port);
}

