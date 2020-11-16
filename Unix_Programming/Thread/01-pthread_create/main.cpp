//
// Created by lbinr on 2020/11/16.
//

#include <iostream>
#include <pthread.h>
#include <unistd.h> //sleep()

using namespace std;

pthread_t ntid;

void* thr_fn( void* arg ){
    cout << "new tid:" << pthread_self() << endl;
}

int main( int argc, char* argv[] ){
    pthread_create( &ntid, NULL, thr_fn, NULL );

    pthread_t tid = pthread_self();
    cout << "main tid:" << tid << endl;
    sleep(1);
}
