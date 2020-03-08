//
// Created by breeze on 2020/3/8.
//

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
    int status;
    pid_t pid=fork();

    // 子进程
    if(pid == 0){
        sleep(15);
        return 24;
    }
    else{
        /**
         *  pid: -1代表等待任意进程，与wait相同
         *  statloc: 子进程返回状态
         *  options: 选项，WNOHANG没有子进程也不会休眠
         */
        while(!waitpid(-1, &status, WNOHANG)){
            sleep(3);
            puts("sleep 3 sec.");
        }

        // 判断是否正常终止，并打印退出码
        if (WIFEXITED(status)){
            printf("child send %d \n", WEXITSTATUS(status));
        }
        return 0;
    }
}