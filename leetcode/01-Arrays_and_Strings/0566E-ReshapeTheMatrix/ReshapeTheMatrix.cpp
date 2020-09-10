// 1.遍历原始矩阵，并将元素填充至新矩阵
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        
        if ( nums.size() == 0 || nums[0].size() == 0 ) {
            return nums;
        }
            
        if ( nums[0].size() * nums.size() != r * c ){
            return nums;
        }
        
        vector<vector<int>>::iterator outer_it = nums.begin();
        vector<int>::iterator it = outer_it -> begin();
        
        vector<vector<int>> new_nums;
        for ( int i = 0; i < r; i++ ) {
            vector<int> row;
            for ( int j = 0; j < c; j++ ){
                if ( it == outer_it -> end() ){
                    outer_it++;
                    it = outer_it -> begin();
                }
                row.push_back( *it );
                it++;
            }
            new_nums.push_back( row );
        }
        
        return new_nums;
    }
};

作者：knightliu
链接：https://leetcode-cn.com/problems/reshape-the-matrix/solution/xi-bao-ti-jie-ri-ji-ju-zhen-bian-li-by-knightliu/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。