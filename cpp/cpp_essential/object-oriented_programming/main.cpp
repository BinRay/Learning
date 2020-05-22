//
// Created by lbinr on 2020/5/22.
//

#include "num_sequence.h"
#include "Fibonacci.h"

int main( int argc, char** argv ){
    Fibonacci f(8, 1);

    //f.print();
    cout << "the default "<< f.what_am_i() <<" sequence is: " << f << endl;

    cout << "the 20th elem is:" << f.elem( 19 ) << endl;
    return 0;
}

