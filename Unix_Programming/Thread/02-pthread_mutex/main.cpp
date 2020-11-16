//
// Created by lbinr on 2020/11/16.
//

#include <iostream>
#include <pthread.h>
#include <unistd.h> //sleep()

using namespace std;

pthread_t ntid;
int shared_data;

void* thr_fn( void* arg ){
    cout << "begin new tid:" << pthread_self() << endl;
    for ( int i = 0; i < 10000; i++ ){
        shared_data++;
    }
}

int main( int argc, char* argv[] ){
    pthread_create( &ntid, NULL, thr_fn, NULL );

    pthread_t tid = pthread_self();
    cout << "begin main tid:" << tid << endl;

    for ( int i = 0; i < 10000; i++ ){
        shared_data--;
    }

    pthread_join( ntid, NULL );

    cout << "shared_data:" << shared_data << endl;
}
