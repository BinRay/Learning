class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 右上角顶点的二叉搜索树（bst）
        
        int M = matrix.size() - 1;
        int N = matrix.empty() ? -1 : matrix[0].size() - 1;
        
        if ( M == -1 || N == -1  || target < matrix[0][0] || target > matrix[M][N]) return false;
        
        int m = 0;
        int n = N;
        while ( m <= M && n >= 0 ){
            if ( matrix[m][n] < target ){
                m = m + 1;
            } else if ( matrix[m][n] > target ){
                n--;
            } else {
                return true;
            }
        }
        
        return false;

    }
    
};
