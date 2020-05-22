//
// Created by lbinr on 2020/5/22.
//

#ifndef OBJECT_ORIENTED_PROGRAMMING_NUM_SEQUENCE_H
#define OBJECT_ORIENTED_PROGRAMMING_NUM_SEQUENCE_H

#include <iostream>
#include <vector>

using namespace std;

class num_sequence{
public:
    // return the value at the position of the number sequence. All derived series should be the same.
    int elem( int pos );

    // return the exact type of the object.
    const char* what_am_i() const;

    // output the series
    ostream& print( ostream &os = cout );

    // todo: return the value of max pos of the series
    static int max_elems();

    // due to other class will be derived from this class, destructors should be virtual.
    virtual ~num_sequence() = default;

    int length() const{ return _length; }
    int beg_pos() const{ return _beg_pos; }

protected:

    // initialize all non-static member data. constructor won't be invoked by other users except its derived class.
    num_sequence(int length, int beg_pos, vector<int>& re):
    _length( length ), _beg_pos( beg_pos ), _relems( re )
    {}

    // generate numbers until the position of the number sequence
    virtual void gen_elems( int pos ) const = 0;

    // check if pos is valid
    bool check_integrity( int pos, int size );

    const static int _max_elems = 1024;

    int _length;
    int _beg_pos;   // start with 0;

    // reference couldn't be null, it must refer to sth.
    vector<int>& _relems;
};

// in head file, function definition must be declared with "inline"
inline ostream& operator<<( ostream& os, num_sequence& s){
    s.print(os);
    return os;
}

#endif //OBJECT_ORIENTED_PROGRAMMING_NUM_SEQUENCE_H
