//
// Created by lbinr on 2020/5/22.
//

#include "num_sequence.h"

using namespace std;

bool num_sequence::check_integrity(int pos, int size) {
    if ( pos <= 0 || pos > _max_elems ){
        return false;
    }

    if ( pos > size ){
        // this will invoke derived class's function through 'virtual'.
        gen_elems( pos );
    }
    return true;
}

int num_sequence::max_elems() {
    return _max_elems;
}

int num_sequence::elem(int pos) {
    if ( !check_integrity( pos, _relems.size() ) ){
        return 0;   // 0 shows sth is wrong.
    }
    return _relems[ pos ];
}

const char *num_sequence::what_am_i() const {
    return typeid( *this ).name();
}

ostream &num_sequence::print(ostream &os) {
    if ( !check_integrity( _beg_pos+_length, _relems.size() ) ){
        cerr << "exceed the max range" << endl;
        return os;
    }
    os << "(" << _length << "," << _beg_pos << ")";
    for ( int ix = _beg_pos; ix < _beg_pos + _length; ix++){
        os << _relems[ ix ];
        if ( ix + 1 != _beg_pos + _length ){
            os << ", ";
        }
    }
    return os;
}
