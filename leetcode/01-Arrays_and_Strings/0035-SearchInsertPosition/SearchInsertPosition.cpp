#include <vector>
#include <iostream>

using namespace std;

// binary search
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int first = 0; 
        int last = nums.size() - 1;
        int mid = ( first + last ) / 2;

        while ( first <= last ) {
            if ( nums[mid] > target ){
                last = mid - 1;
                mid = ( first + last ) / 2;
            } else if ( nums[mid] < target ) {
                first = mid + 1;
                mid = ( first + last ) / 2;
            } else {
                return mid;
            }
        }

        return first;

    }
};


int main( int argc, char** argv ) {
    vector<int> nums { 1, 3, 5, 6 };
    int target = 5;
    Solution s;
    cout << s.searchInsert( nums, target ) << endl;

    for ( auto& num: nums ){
        cout << num << " ";
    }
}