//
// Created by lbinr on 2020/5/14.
//

// Import 'function object', which is more efficient than function pointer.
// bind2nd() is a function object adapter, which can bind a fixed value to the 2nd parameter.
// find_if() is alse a stl function. it can accept function object.

#include <functional>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> filter ( const vector<int> & vec, int val, const less<int> &lt ){
    vector<int> nvec;
    vector<int>::const_iterator iter = vec.begin();

    while ( ( iter = find_if( iter, vec.end(), bind2nd( lt, val ) ) ) != vec.end() ){
        nvec.push_back( *iter );
        iter++;
    }

    return nvec;
}

int main( int argc, char** argv){

    const int elem_size = 8;
    int ia[ elem_size ] = { 12, 8, 43, 0, 6, 21, 3, 7};
    vector<int> ivec( ia, ia+8 );

    vector<int> nvec = filter( ivec, 10, less<int>() );

    for ( int i = 0; i < nvec.size(); i++){
        cout << nvec[i] << endl;
    }

}