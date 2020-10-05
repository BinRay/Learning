#include <vector>
#include <algorithm>

using namespace std;

// 双指针（左右指针去掉一层循环，O(n3) ）
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        vector<vector<int>> ans;

        int n = nums.size();

        if ( n < 4 ){
            return ans;
        }

        // 排序，循环式过滤掉相同元素，去重用
        sort( nums.begin(), nums.end() );

        for ( int a = 0; a < n - 3; a++ ){

            // 当第一个数为nums[a]时， 该算法会把所有target-nums[a]的组合都计算出来，因此再遇到nums[a]时，要过滤掉，避免重复。
            if ( a > 0 && nums[a] == nums[a-1] ){
                continue;
            }

            // 剪枝，最小的4个数都比target大，所以后面就不用看了。
            if ( nums[a] + nums[a+1] + nums[a+2] + nums[a+3]  > target ){
                break;
            }

            // nums[a]与最大的3个数相加都小于target，这层循环就不必看了。需要让a再大一些。
            if ( nums[a] + nums[n-1] + nums[n-2] + nums[n-3] < target ){
                continue;
            }

            for ( int b = a + 1; b < n - 2; b++ ){
                if ( b > a + 1 && nums[b] == nums[b-1] ){
                    continue;
                }

                if ( nums[a] + nums[b] + nums[b+1] + nums[b+2] > target ){
                    break;
                }

                if ( nums[a] + nums[b] + nums[n-2] + nums[n-1] < target ){
                    continue;
                }

                int c = b + 1;
                int d = n - 1;

                while ( c < d ){
                    int sum = nums[a] + nums[b] + nums[c] + nums[d];
                    if ( sum == target ){
                        vector<int> v = { nums[a], nums[b], nums[c], nums[d] };
                        ans.emplace_back( v );
                        do {
                            c++;
                        } while( nums[c] == nums[c-1] && c < d );
                        do {
                            d--;
                        } while( nums[d] == nums[d+1] && c < d );
                    } else if ( sum < target ){
                        do {
                            c++;
                        } while( nums[c] == nums[c-1] && c < d );
                    } else {
                        do {
                            d--;
                        } while( nums[d] == nums[d+1] && c < d );
                    }
                }
            }

        }

        return ans;

    }
};

int main( int argc, char* argv[] ){
    vector<int> nums = { -2,-1,-1,1,1,2,2 };
    int target = 0;
    Solution so;
    so.fourSum( nums, 0 );
}