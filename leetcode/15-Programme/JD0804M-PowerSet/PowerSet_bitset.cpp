/**
 * 执行用时：4 ms, 在所有 C++ 提交中击败了61.63%的用户
 * 内存消耗：7.6 MB, 在所有 C++ 提交中击败了100.00%的用户
 * 1. 每种组合都是2**len数字中的一个二进制位表示
 * 2. 遍历，组装即可
 * 
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // bit manipulation: O(n*2**n)
        bitset<128> combination;
        vector<vector<int>> subsets;
        for ( int i = 0; i < pow( 2, nums.size() ); i++ ){
            combination = i;
            vector<int> subset;
            for ( int j = 0; j < nums.size(); j++ ){
                if ( combination.test(j) ){
                    subset.push_back( nums[j] );
                }
            }
            subsets.push_back( subset );
        }
        return subsets;
    }
};