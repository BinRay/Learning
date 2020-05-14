//
// Created by lbinr on 2020/5/14.
//

// Use function call instead of comparing values directly by passing arround a function pointer.
// Therefore, it can support more compare operations
// Besides, we use a parameter to represent the filter value

#include <vector>
#include <iostream>
using namespace std;

bool less_than ( int v1, int v2 ){
    return v1 < v2 ;
}

bool greater_than ( int v1, int v2 ){
    return v2 > v1;
}

vector<int> filter ( const vector<int> &vec, int filter_value, bool (*pred)( int, int ) ){
    vector<int> nvec;

    for ( int ix = 0; ix < vec.size(); ix++){
        if ( pred( vec[ix], filter_value) ){
            nvec.push_back( vec[ix] );
        }
    }

    return nvec;
}

int main( int argc, char** argv){

    const int elem_size = 8;
    int ia[ elem_size ] = { 12, 8, 43, 0, 6, 21, 3, 7};
    vector<int> ivec( ia, ia+8 );

    vector<int> nvec = filter( ivec, 10, less_than );

    for ( int i = 0; i < nvec.size(); i++){
        cout << nvec[i] << endl;
    }

}