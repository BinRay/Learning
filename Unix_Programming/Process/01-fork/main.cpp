//
// Created by lbinr on 2020/11/16.
//

#include <iostream>
#include <unistd.h> // fork()

using namespace std;

int main( int argc, char* argv[] ){
    pid_t pid = fork();

    if ( pid == 0 ){
        cout << "child:" << getpid() << endl;
    } else {
        cout << "parent:" << getpid() << endl;
        sleep(1);
    }

}
