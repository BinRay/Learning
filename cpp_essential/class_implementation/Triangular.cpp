//
// Created by lbinr on 2020/5/19.
//

#include "Triangular.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> Triangular::_elems;
int Triangular::_max_elems = 50;

Triangular::Triangular(){
    _length = 1;
    _beg_pos = 1;
    _next = 0;
}

Triangular::Triangular(int len) {
    _beg_pos = 1;
    _next = _beg_pos;
    _length = len > 0 ? len : 1;
}

Triangular::Triangular( int len, int bp ){

    _length = len > 0 ? len : 1;
    _beg_pos = bp > 0 ? bp : 1;
    _next = _beg_pos - 1;

}

Triangular::Triangular( const Triangular& rhs )
    :_length( rhs._length ), _beg_pos( rhs._beg_pos ), _next( rhs._beg_pos-1 ){
    // pass
}

Triangular& Triangular::copy( const Triangular& rhs ){
    // it's wise to check if the two objects are equivalent before copying.
    if ( this != &rhs ){
        _length = rhs._length;
        _beg_pos = rhs._beg_pos;
        _next = rhs._beg_pos - 1;
    }
    return *this;
}

// "const" keyword is also needed in the method definition if this method is const.
int Triangular::elem( int pos ) const{
    return _elems[ pos-1 ];
}

bool Triangular::next( int &value ) const{
    if ( _next < _beg_pos + _length -1 ){
        value = _elems[_next++];
        return true;
    }
    return false;
}

// "static" keyword is not necessary in the definition.
bool Triangular::is_elem( int value ){
    if ( !_elems.size() || _elems[ _elems.size()-1] < value ){
        gen_elems_to_value( value );
    }

    vector<int>::iterator found_it;
    vector<int>::iterator end_it = _elems.end();

    found_it = find( _elems.begin(), end_it, value );
    return found_it != end_it;
}

void Triangular::gen_elems_to_value( int value ){
    int ix = _elems.size();
    if ( !ix ){
        _elems.push_back( 1 );
    }
    while ( _elems[ ix -1 ] < value && ix < _max_elems ){
        // cout << "elems to value: " << ix*(ix+1)/2 << endl;
        ++ix;
        _elems.push_back( ix*(ix+1)/2 );
    }
    if ( ix == _max_elems ){
        cerr << "Triangular Sequence: oops: value too large"
             << value << " -- exceeds max size of "
             << _max_elems << endl;
    }
}

void Triangular::gen_elements( int length ){
    if ( length < 0 || length > _max_elems ){
        cerr << "wrong length parameter" << endl;
        //todo: throw exception
        return;
    }
    if ( _elems.size() < length ){
        int ix = _elems.size() ? _elems.size() + 1 : 1;     //start with 1
        for ( ; ix <= length; ++ix){
            _elems.push_back( ix * (ix+1) / 2 );
        }
    }
}

void Triangular::display( int length, int beg_pos, ostream &os ) {
    int display_length =  beg_pos + length - 1;
    if( display_length >= _elems.size() ){
        gen_elements( display_length );
    }
    cout << "(" << length << "," << beg_pos << ")" << " ";
    for (int ix = beg_pos-1; ix < beg_pos - 1 + length; ix++){
        cout << _elems[ix] << " ";
    }
}

// overload iostream operators
ostream& operator<<( ostream& os, const Triangular& rhs ){
    Triangular::display( rhs.length(), rhs.beg_pos(), os );
    return os;
}