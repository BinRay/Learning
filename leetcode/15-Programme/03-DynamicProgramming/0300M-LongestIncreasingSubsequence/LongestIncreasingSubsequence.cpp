#include <vector>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // dp[i] = max(dp[j]) + 1 当0 <= j < i 且 nums[], 其中dp[i]表示以nums[i]结尾并且nums[i]为最长子序列（LIS）最大值时LIS的长度
        vector<int> dp;
        for ( int i = 0; i < nums.size(); i++ ){
            int max = 0;
            for ( int j = 0; j < i; j++ ){
                if ( nums[j] < nums[i] ){
                    max = max > dp[j] ? max : dp[j];
                }
            }
            dp.push_back( max + 1 );
        }

        int ans = 0;
        for ( auto c: dp ){
            if ( ans < c ){
                ans = c;
            }
        }

        return ans;
    }
};

int main( int argc, char* argv[] ){
    Solution s;
    vector<int> nums = {1,3,6,7,9,4,10,5,6};
    s.lengthOfLIS( nums );
}