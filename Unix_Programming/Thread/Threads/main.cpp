//
// Created by lbinr on 2020/11/16.
//

#include <iostream>
#include <pthread.h>

using namespace std;

int main( int argc, char* argv[] ){
    pthread_t tid = pthread_self();

    cout << "tid:" << tid << endl;
}
