/** 
 * 执行用时：4 ms, 在所有 C++ 提交中击败了61.63%的用户
 * 内存消耗：7.4 MB, 在所有 C++ 提交中击败了100.00%的用户
 * 动态规划：
 * 1. 集合n+1 是 集合n 与 将n+1元素添加集合n中每个子集合构成新集合 的并集
 */

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // dynamic programming
        
        vector<vector<int>> subsets;
        vector<int> empty_set; //empty set
        subsets.push_back( empty_set );
        for ( int i = 0; i < nums.size(); i++ ){
            vector<vector<int>> addition;
            for ( auto subset: subsets ){
                vector<int> new_subset( subset );
                new_subset.push_back( nums[i] );
                addition.push_back( new_subset );
            }
            subsets.insert( subsets.end(), addition.begin(), addition.end() );
        }
        
        return subsets;
    }
        
};