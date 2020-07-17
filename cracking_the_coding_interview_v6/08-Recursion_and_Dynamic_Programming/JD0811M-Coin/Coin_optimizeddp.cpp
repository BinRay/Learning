/**
这是完全背包问题的变种问题，即所有物品可以无限取，但算的是有多少种取法而不是最大价值。
朴素的解法：
1. 在算第i行第j列时，一共有 K + 1 种情况（假设K = j/w[i]），即第i种物品可以取0次、1次、2次...k次。
2. 对于每种情况，有dp_record[i-1][j-k*w[i]]组合（ k = 0, 1, 2, ... K ）。
3. 把2中每种情况的组合数加起来，即是i行j列的总组合数。
然而这种朴素的解法包含三层循环，提交会超时，所以要想办法优化掉一层循环。
作为动态规划的初学者，没有那么多经验，直觉上想，在第i行每算一个j都要取1，2，..., K-1，K种情况，那在算 j-w[i] 时，是不是把 1, 2, ... , K-1 都已经算过了呢？
换句话说，可不可能在算j时，前面的K-1之和直接能拿到，与k相加求得，这样便能省去最里一层循环。
顺着这个思路，就看一下j-w[i]的展开: dp_record[i-1][j- w[i] - k*w[i]] ( k = 0, 1, 2, 3 ... , K-1 )  等价于  dp_record[i-1][j-k*w[i]] ( k = 1, 2, ... K-1, K )。 
这个式子就有点眼熟了，和朴素解法的2相比，只差一个k=0的情况。而k等于0就是指第i种硬币一个都不取的情况，正是dp_record[i-1][j]，所以将两者相加即得第i行第j列的值，即：dp[i][j-w[i]]+dp[i-1][j]。
这两个值都是之前算过的，所以直接可取，省掉一层循环。虽然最后的结果与起初的直觉猜想并不一致，但实际演算后却发现了意外惊喜。
所以个人感悟就是如果经验较少，没有清晰的思路时，就列出表格，猜想规律，推演各项表达式，从而优化。
*/
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