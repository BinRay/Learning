//
// Created by breeze on 2020/3/8.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <iostream>

#define BUF_SIZE 30

using namespace std;

void error_handling(char* message);
void read_childproc(int sig);

int main(int argc, char* argv[]){


    pid_t pid;
    socklen_t adr_sz;
    int str_len, state;
    char buf[BUF_SIZE];

    if(argc != 2){
        printf("Usage: %s <port> \n", argv[0]);
        exit(1);
    }

    // 信号注册
    struct sigaction act;
    act.sa_handler = read_childproc;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    state = sigaction(SIGCHLD, &act, 0);    //成功返回0，失败返回-1

    // 服务端地址绑定
    int serv_sock, clnt_sock;
    struct sockaddr_in serv_adr, clnt_adr;
    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_adr.sin_port = htons(atoi(argv[1]));

    if (bind(serv_sock, (struct sockaddr*) &serv_adr, sizeof(serv_adr)) == -1){
        error_handling("bind() error");
    }

    if(listen(serv_sock, 5) == -1){
        error_handling("listen() error");
    }

    // 主流程
    while(1){
        // 父进程，服务器接收请求
        adr_sz = sizeof(clnt_adr);
        clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_adr, &adr_sz);    // 无请求阻塞
        if (clnt_sock == -1){
            continue;
        } else{
            puts("new client connected...");
        }

        // 创建新子进程
        pid = fork();
        if (pid == -1){
            close(clnt_sock);
            continue;
        }

        if (pid == 0){          // 子进程
            close(serv_sock);   // 关掉监听sock描述符
            cout << "child proc pid:" << pid << endl;
            while((str_len = read(clnt_sock, buf, BUF_SIZE)) != 0){ // EOF 返回0
                write(clnt_sock, buf, str_len);
                memset(buf, 0, str_len);
            }
            close(clnt_sock);
            puts("client disconneted...");
            return 0;
        }else{
            close(clnt_sock);
        }
    }
    close(serv_sock);
    return 0;
}

void read_childproc(int sig){
    pid_t pid;
    int status;
    pid = waitpid(-1, &status, WNOHANG);
    printf("removed proc id: %d \n", pid);
}

void error_handling(char* message){
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}