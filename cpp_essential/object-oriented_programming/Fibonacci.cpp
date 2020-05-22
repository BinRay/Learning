//
// Created by lbinr on 2020/5/22.
//

#include "Fibonacci.h"

vector<int> Fibonacci::_elems;
Fibonacci::Fibonacci(int len, int beg_pos) : num_sequence( len, beg_pos-1, _elems) {}

void Fibonacci::gen_elems( int pos ) const {
    if ( _elems.empty() ){
        _elems.push_back( 1 );
        _elems.push_back( 1 );
    }

    if ( _elems.size() <= pos ){
        int ix = _elems.size();
        int n_2 = _elems[ ix-2 ];
        int n_1 = _elems[ ix-1 ];
        for ( ; ix <= pos; ++ix ){
            int elem = n_2 + n_1;
            _elems.push_back( elem );
            n_2 = n_1;
            n_1 = elem;
        }
    }
}