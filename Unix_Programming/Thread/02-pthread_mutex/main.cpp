//
// Created by lbinr on 2020/11/16.
//

#include <iostream>
#include <pthread.h>
#include <unistd.h>  //sleep()
#include <climits>   //INT_MAX

using namespace std;

pthread_t ntid;
int shared_data;

pthread_mutex_t mtx;

void* thr_fn( void* arg ){
    cout << "begin new tid:" << pthread_self() << endl;
    for ( int i = 0; i < INT_MAX; i++ ){
        pthread_mutex_lock( &mtx );
        shared_data++;
        pthread_mutex_unlock( &mtx );
    }
}

int main( int argc, char* argv[] ){
    pthread_mutex_init( &mtx, NULL );

    pthread_create( &ntid, NULL, thr_fn, NULL );

    pthread_t tid = pthread_self();
    cout << "begin main tid:" << tid << endl;

    for ( int i = 0; i < INT_MAX; i++ ){
        pthread_mutex_lock( &mtx );
        shared_data--;
        pthread_mutex_unlock( &mtx );
    }

    pthread_join( ntid, NULL );

    pthread_mutex_destroy( &mtx );

    cout << "shared_data:" << shared_data << endl;
}
