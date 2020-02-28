//
// Created by bin on 2020/2/28.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#include <iostream>
#include <string>

#include "util.h"
using namespace std;

int main(int argc, char* argv[]){
    int sock;
    struct sockaddr_in serv_addr;
    char message[30];
    int str_len;

    if(argc != 3){
        printf("Usage: %s <IP> <PORT>\n", argv[0]);
        exit(1);
    }

    // 1. 创建ipv4套接字
    sock = socket(PF_INET, SOCK_STREAM, 0);
    if(sock == -1){
        error_handling("socket() error");
    }

    // 地址初始化
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);  //将ip字符串转换为大端（网络）字节序整型ip
    serv_addr.sin_port = htons(atoi(argv[2]));

    // 2. 连接服务器
    if(connect(sock, (struct sockaddr*)(&serv_addr), sizeof(serv_addr)) == -1){
        error_handling("connect() error");
    }

    // 3. 收发数据
    str_len = read(sock, message, sizeof(message)-1);
    if(str_len == -1){
        error_handling("read() error!");
    }

    cout << "server return:" << message << endl;

    close(sock);
}



