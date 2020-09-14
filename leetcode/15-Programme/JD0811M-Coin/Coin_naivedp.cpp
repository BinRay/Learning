// 未经优化的dp算法
// 三层循环会超时


class Solution {
public:
    int waysToChange(int n) {
        // 初始化硬币面额
        vector<int> w = { 1, 5, 10, 25 };
        
        // 初始化二维dp表
        vector<vector<int>> dp_record;
        vector<int> record_0( n+1, 1 );
        
        dp_record.push_back( record_0 );
        
        
        // 状态转移方程
        for ( int i = 1; i < w.size(); i++ ){
            vector<int> record_i;
            for ( int j = 0; j <= n; j++ ){
                int i_j = 0;                         // 第i行，第j个元素
                for( int k = 0; k <= j/w[i]; k++ ){
                    i_j += dp_record[i-1][j-w[i]*k];
                    i_j %= 1000000007;
                }
                record_i.push_back( i_j );
            }
            dp_record.push_back( record_i );
        }
        
        return dp_record[3][n];
    }
    
    
};