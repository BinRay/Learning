//
// Created by lbinr on 2020/5/19.
//

#ifndef CLASS_IMPLEMENTATION_TRIANGULAR_ITERATOR_H
#define CLASS_IMPLEMENTATION_TRIANGULAR_ITERATOR_H
#include "Triangular.h"

class Triangular_iterator{
public:
    explicit Triangular_iterator( int index ) : _index( index -1 ){}
    bool operator==( const Triangular_iterator& ) const;
    bool operator!=( const Triangular_iterator& ) const;
    int operator*() const;
    Triangular_iterator& operator++();      //prefix version of ++
    const Triangular_iterator operator++( int );  //postfix version of ++
private:
    void check_integrity() const;
    int _index;
};

#endif //CLASS_IMPLEMENTATION_TRIANGULAR_ITERATOR_H
