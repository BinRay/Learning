#include <vector>

using namespace std;

// 执行用时：4 ms, 在所有 C++ 提交中击败了45.37%的用户
// 内存消耗：8.1 MB, 在所有 C++ 提交中击败了5.07%的用户

class Solution {
public:
    int rob(vector<int>& nums) {
        // 令opt[i-1]表示i个房子所能取得的最大值
        // 令opt_excp[i-1]表示，不取第一个房子所能取得的最大值。opt_excp就是简单的打家劫舍1的问题，不带环能取的最大值。
        // 令opt_inc[i-1]表示，取第一个房子是所能取得的最大值，不带环，也是简单的打家劫舍1的问题。

        if ( nums.size() == 0 ) return 0;
        if ( nums.size() == 1 ) return nums[0];
        if ( nums.size() == 2 ) return max( nums[0], nums[1] );


        vector<int> opt_excp;
        opt_excp.push_back( 0 );
        opt_excp.push_back( nums[1] );
        opt_excp.push_back( max( nums[1], nums[2] ) );

        vector<int> opt_inc;
        opt_inc.push_back( nums[0] );
        opt_inc.push_back( max( nums[0], nums[1] ) );
        opt_inc.push_back( max( opt_inc[1], nums[0] + nums[2] ) );

        vector<int> opt;
        opt.push_back( nums[0] );   // 取第1个房子
        opt.push_back( max( nums[0], nums[1] ) );   // 取第2个房子
        opt.push_back( max( opt[1], nums[2] ) );       // 取第3个房子

        if ( nums.size() == 3 ) return opt.back();

        for ( int i = 3; i < nums.size(); i++ ){
            opt_inc.push_back( max( opt_inc[i-1], opt_inc[i-2] + nums[i] ) );
            opt_excp.push_back( max( opt_excp[i-1], opt_excp[i-2] + nums[i] ) );
            opt.push_back( max( opt_inc[i-1], opt_excp[i-2]+nums[i] ) );
        }

        return opt.back();
    }
};

int main( int argc, char* argb[] ){
    vector<int> v = {1,2,3,1};
    Solution s;
    s.rob( v );

}