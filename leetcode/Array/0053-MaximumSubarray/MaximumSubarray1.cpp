#include <vector>
#include <iostream>

using namespace std;

// no need to find out the exact subarray
// greedy algorithm

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0];
        int prev_sum = nums[0];
        int curr_sum = nums[0];
        
        for ( int i = 1; i < nums.size(); i++ ){
            
            if ( prev_sum < 0){
                curr_sum = nums[i];
                prev_sum = nums[i];
            } else {
                curr_sum = prev_sum + nums[i];
                prev_sum += nums[i];
            }

            if ( curr_sum > max_sum ) {
                max_sum = curr_sum;
            }
        }

        return max_sum;
    }
};

int main( int argc, char** argv ) {
    vector<int> nums = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution s;
    cout << s.maxSubArray( nums );
    
}