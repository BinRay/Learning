#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // 使用标记数组记录已添加到路径的状态
        
        sort( nums.begin(), nums.end() );
        vector<int> marked;
        marked.resize( nums.size(), 0 );
        vector<vector<int>> ans;
        vector<int> track;
        bt( ans, nums, track, marked );
        
        return ans; 
        
    }
    
    void bt( vector<vector<int>> & ans, vector<int> & nums, vector<int> & track, vector<int> & marked ){
        
        cout << track.size() << "|" << nums.size() << endl;
        if ( track.size() == nums.size() ){
            ans.emplace_back( track );
        } else {
            for ( int i = 0; i < nums.size(); i++ ){
                if ( marked[i] || i > 0 && nums[i] == nums[i-1] && !marked[i-1]  ){   // 已标记退出，或者重复数只选择第一个未被标记的
                    continue;
                }
                
                marked[i] = 1;
                track.emplace_back( nums[i] );
                bt( ans, nums, track, marked );
                track.pop_back();
                marked[i] = 0;
            }
        }
        
    }
};

int main( int argc, char* argv[] ){
    Solution s;
    vector<int> nums = { 1, 1, 2 };
    s.permuteUnique( nums );
}