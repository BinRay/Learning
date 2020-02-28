#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#include <iostream>
#include <string>

using namespace std;

void error_handling(string message);


int main(int argc, char* argv[]){
	int serv_sock;	//监听套接字
	int clnt_sock;	//与客户端通信套接字

	struct sockaddr_in serv_addr;	//服务器地址信息，ipv4地址族结构体
	struct sockaddr_in clnt_addr;	//客户端地址信息
	socklen_t clnt_addr_size;	//客户端地址长度
	
	string message = "hello, socket";
	
	if (argc != 2){
		printf("Usage: %s <port>\n", argv[0]);
		exit(1);
	}
	
	//1. 创建服务器套接字，指定协议：ipv4互联网协议族，面向连接的流式套接字，tcp协议;	//最后一个参数也通常写0
	serv_sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);	//最后一个参数也通常写0
	if(serv_sock == -1){
		error_handling("socket() error");
	}
	
	// 服务器地址初始化
	memset(&serv_addr, 0, sizeof(serv_addr));	//确保serv_addr的sin_zero[8]为0
	serv_addr.sin_family = AF_INET;			//ipv4 互联网地址族
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);	//对本机所有网卡ip有效,转为网络（大端）字节序（内存地址地位为数据的高位）
	serv_addr.sin_port = htons(atoi(argv[1]));	//端口
	
	//2. 为监听套接字分配地址和端口
	if (bind(serv_sock, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) == -1){	//第二个参数不只可以接受ipv4地址，所以需要转换成通用地址，按位赋值
		error_handling("bind() error");
	}
	
	//3. 将套接字设置为监听状态
	if(listen(serv_sock, 5) == -1){			//第2个参数为队列长度
		error_handling("listen() error");
	}
	
	clnt_addr_size = sizeof(clnt_addr);
	//4. 在监听套接字上接受请求

	clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);
	if(clnt_sock == -1){
		error_handling("accept() error");
	}

	//netstat 此时该套接字状态LISTEN

	//5. 收发数据
	write(clnt_sock, message.c_str(), sizeof(message));

	//6. 关闭套接字（文件描述符）
	close(clnt_sock);
	close(serv_sock);	
}


void error_handling(string message){
	std::cout << message << std::endl;
	exit(1);
}




























