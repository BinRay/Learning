//
// Created by breeze on 2020/3/8.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void read_childproc(int sig){
    int status;
    pid_t id = waitpid(-1, &status, WNOHANG);
    if (WIFEXITED(status)){
        printf("Removed proc id: %d \n", id);
    }
}

int main(int argc, char* argv[]){
    pid_t pid;
    // 信号注册及对应结构体
    struct sigaction act;
    act.sa_handler = read_childproc;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    sigaction(SIGCHLD, &act, 0);

    pid = fork();
    if (pid == 0){  //子进程
        puts("Hi! I'm child process 1");
        sleep(5);
        return 1;
    }
    else{           //父进程
        printf("Child proc 1 id: %d \n", pid);
        pid = fork();
        if(pid == 0){
            puts("Hi! I'm child process 2");
            sleep(10);
            return 2;
        }
        else{
            int i;
            printf("Child proc 2 id: %d \n", pid);
            for(int i = 0; i < 5; i++ ){
                puts("wait...");
                sleep(5);
            }
        }
    }
    return 0;
}
