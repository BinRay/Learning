//
// Created by lbinr on 2020/5/19.
//

#ifndef CLASS_IMPLEMENTATION_TRIANGULAR_H
#define CLASS_IMPLEMENTATION_TRIANGULAR_H

#include <iostream>
#include <vector>
#include "Triangular_iterator.h"

using namespace std;

class Triangular {
public:
    // friend class
    friend class Triangular_iterator;
//    friend int Triangular_iterator::operator*() const;
//    friend void Triangular_iterator::check_integrity() const;

    // constructor
    Triangular();
    Triangular( int len );
    Triangular( int len, int beg_pos );

    Triangular( const Triangular &rhs );

    Triangular& copy( const Triangular &rhs );

    // const member function
    int length()    const   { return _length; }
    int beg_pos()   const   { return _beg_pos; }
    int elem( int pos )     const;

    // non-const member function
    bool next( int &val ) const;
    void next_reset()   { _next = _beg_pos -1; }

    // static member function, shouldn't access any non-static data.
    static bool is_elem( int value );
    static void gen_elements( int length );
    static void gen_elems_to_value( int value );
    static void display( int length, int beg_pos, ostream &os = cout);

    // about iterater, nested type
    typedef Triangular_iterator iterator;
    iterator begin() const {
        return iterator(_beg_pos);
    }
    iterator end() const { return iterator( _beg_pos + _length ); }



private:
    int _length;    // amount of elements
    int _beg_pos;   // beginning position, start with 1. It's the start of the series rather than vector index.
    mutable int _next;       // next position of iteration, this variable can be changed in const method due to "mutable" statement.

    static int _max_elems;
    static vector<int> _elems;   // static data member
};

ostream& operator<<( ostream& os, const Triangular& rhs );

#endif //CLASS_IMPLEMENTATION_TRIANGULAR_H
