//
// Created by lbinr on 2020/5/22.
//

#ifndef NUM_SEQUENCE_FIBONACCI_H
#define NUM_SEQUENCE_FIBONACCI_H

#include <vector>
#include "num_sequence.h"

using namespace std;

class Fibonacci: public num_sequence{

public:
    Fibonacci( int len = 1, int beg_pos = 1);

    ~Fibonacci()= default;


protected:
    // 'virtual' is not necessary, because it has been declared in the base class. 'const' couldn't be ignored.
    virtual void gen_elems( int pos ) const;

    static vector<int> _elems;
};

#endif //NUM_SEQUENCE_FIBONACCI_H
