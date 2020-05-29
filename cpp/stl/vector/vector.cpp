#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// some way to initialize vector:
void initialize(){
    
    std::vector<int> primes {2, 3, 5, 7, 11, 13, 17, 19};
    std::vector<double> values(20);
    std::vector<double> init_values(20, 1.0);

    // copy constructor: init from another vector
    std::vector<double> values_copy(values);

    // range constructor: init fragment
    std::vector<double>values_range(std::begin(values), std::begin(values)+3);
}

void del_elem( vector<int> &nums ){
    if ( ! nums.empty() ) {
        swap( nums[1], *(nums.end()-1) );
        nums.pop_back();
    }
}

int main( int argc, char** argv ){
    
    std::vector<int> nums {2, 3, 5, 7, 11, 13, 17, 19};
    del_elem( nums );

    for ( auto& num: nums){
        cout << num << " ";
    }
}