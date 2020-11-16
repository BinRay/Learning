//
// Created by lbinr on 2020/11/16.
//

#include <iostream>
#include <pthread.h>
#include <unistd.h>  // sleep()
#include <climits>   // INT_MAX
#include <cstdlib>   // rand()

using namespace std;

pthread_t c_tid;
pthread_t p_tid;

struct msg{
    struct msg *m_next;
    int data;
};

struct msg* workq;   //任务队列

pthread_mutex_t qlock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t qready = PTHREAD_COND_INITIALIZER;

[[noreturn]] void process_msg(){
    struct msg *mp;
    for ( ; ; ){
        pthread_mutex_lock( &qlock );
        while ( workq == NULL ){
            pthread_cond_wait( &qready, &qlock );
        }
        mp = workq;
        workq = mp -> m_next;
        pthread_mutex_unlock( &qlock );

        cout << "customer:" << mp -> data << endl;
        delete mp;
    }
}

void enqueue_msg(){
    struct msg *mp = new msg;
    mp -> data = rand();
    pthread_mutex_lock( &qlock );
    mp -> m_next = workq;
    workq = mp;
    cout << "producer:" << mp -> data << endl;
    pthread_mutex_unlock( &qlock );

    pthread_cond_signal( &qready );
}


void* customer( void* arg ){
    process_msg();
}

void* producer( void* arg ){
    for ( int i = 0; i < 10; i++ ){
        enqueue_msg();
    }
}

int main( int argc, char* argv[] ){

    pthread_create( &ntid, NULL, customer, NULL );
    pthread_create( &ntid, NULL, producer, NULL );

    pthread_join( c_tid, NULL );
    pthread_join( p_tid, NULL );
    
}
