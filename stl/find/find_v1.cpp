//
// Created by lbinr on 2020/5/12.
//

#include <iostream>
#include <vector>
#include <list>

using namespace std;

// another way to implement find(), which is suitable for all kinds of sequence containers, such as vector or list
template <typename IteratorType, typename elemType>
IteratorType find( IteratorType first, IteratorType last, const elemType &value ){
    for ( ; first != last; ++first ){
        if ( value == *first ){
            return first;
        }
    }
    return last;
}

int main( int argc, char** argv){

    const int asize = 8;
    int ia[asize] =  { 1, 1, 2, 3, 5, 8, 13, 21};

    vector<int> ivec( ia, ia+asize );
    list<int> ilist( ia, ia+asize );

    int target = 1024;

    // normal array
    int *pia = find ( ia, ia+asize, target);
    if ( pia != ia+asize ){
        cout << *pia << endl;
    }

    // vector
    vector<int>:: iterator it;
    it = find( ivec.begin(), ivec.end(), target);
    if ( it != ivec.end()){
        cout << *it << endl;
    }

    // list
    list<int>::iterator iter;
    iter = find( ilist.begin(), ilist.end(), target);
    if ( iter != ilist.end()){
        cout << *iter << endl;
    }

}



