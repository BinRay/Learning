//
// Created by bin on 2020/2/28.
//

#ifndef SOCKET_UTIL_H
#define SOCKET_UTIL_H

#include <iostream>
#include <stdio.h>

using namespace std;

inline void error_handling(char* message){
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}

inline void error_handling(string message){
    cout << message << endl;
}

#endif //SOCKET_UTIL_H
