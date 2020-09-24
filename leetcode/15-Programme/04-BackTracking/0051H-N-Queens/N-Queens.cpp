// 执行用时：8 ms, 在所有 C++ 提交中击败了90.30%的用户
// 内存消耗：7.2 MB, 在所有 C++ 提交中击败了90.56%的用户
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> ans;
        
        string init_row( n, '.' );
        vector<string> track( n, init_row );       // 盘面的一种情况 
        int row_idx = 0;
        
        bt( ans, track, 0, n );
        
        return ans;
    }
    
    void bt( vector<vector<string>> & ans, vector<string> & track, int row_idx, int n ){
        if ( row_idx == n ){
            ans.emplace_back( track );
        } else {
            for ( int col_idx = 0; col_idx < n; col_idx++ ){
                if ( is_attacked( track, row_idx, col_idx, n ) ){
                    continue;
                } else {
                    track[row_idx][col_idx] = 'Q';    // 放皇后
                    bt( ans, track, row_idx + 1, n );   // 递归到下一行
                    track[row_idx][col_idx] = '.';    // 撤销皇后
                }
            }
        }
    }
    
    bool is_attacked( vector<string> & track, int row_idx, int col_idx, int n ){
        
        // 检查纵行是否有皇后
        for ( int i = row_idx - 1; i >= 0; i-- ){
            if ( track[i][col_idx] == 'Q' ){
                return true;
            }
        }
        
        
        // 检查斜线是否有皇后
        int i, j;
        for ( i = row_idx - 1, j = col_idx - 1; i >= 0 && j >= 0; i--, j-- ){
            if ( track[i][j] == 'Q' ){
                return true;
            }
        }
        
        for ( i = row_idx - 1, j = col_idx + 1; i >= 0 && j < n; i--, j++ ){
            if ( track[i][j] == 'Q' ){
                return true;
            }
        }
        
        return false;
    }
};
