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

#define BUF_SIZE 1024
#define DATA_LEN_INDICATION 4

using namespace std;

int main(int argc, char* argv[]){
    int sock;
    struct sockaddr_in serv_addr;
    char send_message[BUF_SIZE];

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
    cout << "connected..." << endl;

    // 3. 收发数据
    while(1){
        fputs("Input message(Q to quit):", stdout);
        fgets(send_message, BUF_SIZE, stdin);

        // 退出客户端，相等为0而不是1
        if(!strcmp(send_message, "q\n") || !strcmp(send_message, "Q\n")){
            // 连接半关闭，此处意义不大，但是可以说明问题：当不再需要发送，但是还需要接收时，则只断开输出流
            shutdown(sock, SHUT_WR);
            break;
        }

        write(sock, send_message, BUF_SIZE);
        // 应用层协议，前4个字节表示数据长度（包括这4个）


        // tcp无边界
        char recv_message[BUF_SIZE];
        int data_len;
        read(sock, &data_len, DATA_LEN_INDICATION);
        cout << data_len << endl;
        int recv_len = 0;
        while(recv_len + DATA_LEN_INDICATION < data_len){
            recv_len += read(sock, &recv_message[recv_len], BUF_SIZE);
        }
        cout << "server return:" << endl << recv_message << endl;

    }
    close(sock);
}



