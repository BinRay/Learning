//
// Created by lbinr on 2020/5/14.
//

// Use function template and iterator to support more element type and more container type.

#include <functional>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>     // std::back_inserter

using namespace std;

template <typename InputIterator, typename OutputIterator, typename ElemType, typename Comp>
OutputIterator filter ( InputIterator first, InputIterator last, OutputIterator at, const ElemType &val, Comp pred ){

    while ( ( first = find_if( first, last, bind2nd( pred, val ) ) ) != last ){
        *at++ = *first++;
    }

    return at;
}

int main( int argc, char** argv){

    const int elem_size = 8;
    int ia[ elem_size ] = { 12, 8, 43, 0, 6, 21, 3, 7};
    vector<int> ivec( ia, ia+8 );

    //vector<int> nvec( 8 );
    //filter( ivec.begin(), ivec.end(), nvec.begin(), 10, less<int>() );

    // import "insertion adapter" to transform assignment into push_back(), and we don't need to initialize the capacity of the vector.
    vector<int> nvec;
    filter( ivec.begin(), ivec.end(), back_inserter(nvec), 10, less<int>());

    for ( int i = 0; i < nvec.size(); i++){
        cout << nvec[i] << endl;
    }

}