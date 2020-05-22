//
// Created by lbinr on 2020/5/14.
//

#include <vector>
#include <iostream>

using namespace std;

// this function doesn't have any flexibility.
vector<int> less_than_10( const vector<int> &vec ){
    vector<int> nvec;

    for ( int ix = 0; ix < vec.size(); ++ix){
        if ( vec[ix] < 10 ){
            nvec.push_back(vec[ix]);
        }
    }

    return nvec;
}

int main( int argc, char** argv){

    const int elem_size = 8;
    int ia[ elem_size ] = { 12, 8, 43, 0, 6, 21, 3, 7};
    vector<int> ivec( ia, ia+8 );

    vector<int> nvec = less_than_10( ivec );

    for ( int i = 0; i < nvec.size(); i++){
        cout << nvec[i] << endl;
    }

}
