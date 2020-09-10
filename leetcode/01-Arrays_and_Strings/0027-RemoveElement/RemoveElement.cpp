#include <vector>
#include <iostream>

using namespace std;

// index is to find out element equivalent to val, and change this element to the value which picked up beyond the boundary and not equals to val.
// O(n)

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>::iterator index = nums.begin();
        vector<int>::iterator boundary = nums.end();
        while ( index < boundary ) {
            if ( *index == val ){
                --boundary;
                while ( boundary > index && *boundary == val ){
                    --boundary;
                }
                *index = *boundary;
            }
            ++index;
        } 
        return boundary - nums.begin();
    }
};

int main( int argc, char** argv){
    vector<int> nums = { 0, 1, 2, 2, 3, 0, 4, 2 };
    int val = 2;
    Solution s;
    cout << s.removeElement( nums, val ) << endl;
    for ( auto num: nums){
        cout << num << " ";
    }
}