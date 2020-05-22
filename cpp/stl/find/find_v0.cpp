//
// Created by lbinr on 2020/5/11.
// an implementation of find()
//

#include <iostream>
#include <vector>

using namespace std;

// only used for contiguous storage, like array or vector
template <typename elemType>
inline elemType* begin(const vector<elemType> &vec){
    return vec.empty() ? 0 : &vec[0];
}

template <typename elemType>
const elemType* find( const elemType *first, const elemType *last, const elemType &value){
     if ( !first || !last ){
         return 0;
     }

     for( ; first != last; ++first ){
         if ( *first == value ){
             return first;
         }
     }

     return 0;
}




int main( int argc, char** argv){
    int a[] = {16, 2, 77, 29};
    std::vector<int> v(a, a + sizeof(a) / sizeof(int));

    cout << "array find" << endl;
    cout << *find(a, a+4, 2) << endl;

    cout << "vector find" << endl;
    cout << *find( &v[0], &v[4], 77 ) << endl;

}


