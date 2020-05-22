//
// Created by lbinr on 2020/5/19.
//

#include "Triangular_iterator.h"
#include "Triangular.h"

using namespace std;

inline void Triangular_iterator::check_integrity() const {
    if ( _index >= Triangular::_max_elems ){
        //throw iterator_overflow();
    }

    if ( _index >= Triangular::_elems.size() ){
        Triangular::gen_elements( _index + 1 );
    }
}

inline bool Triangular_iterator::operator==( const Triangular_iterator& rhs ) const {
    return _index == rhs._index;
}

inline bool Triangular_iterator::operator!=(const Triangular_iterator& rhs) const {
    return !( *this == rhs );
}

int Triangular_iterator::operator*() const {
    check_integrity();
    return Triangular::_elems[_index];
}

Triangular_iterator &Triangular_iterator::operator++() {
    ++_index;
    check_integrity();
    return *this;
}

const Triangular_iterator Triangular_iterator::operator++( int ) {
    Triangular_iterator tmp = *this;
    ++_index;
    check_integrity();
    return tmp;
}


