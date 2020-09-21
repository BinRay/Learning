/**
解题思路
这是一个二维动态规划问题，纵坐标可看成第一个字符串，横坐标可看作第二个字符串。
对于每个单元格dp[i][j]，代表以第一个字符串的第i个字符、第二个字符串的第j个字符结尾的两个子字符串最长公共子序列（简记LCS）的长度，这也是这个动态规划的子问题。
对于任意dp[i][j]，状态转移方程为：
当text1[i]与text2[j]相等时，那么这个相等的字符一定是这个子问题的LCS的结尾字符，其长度值为dp[i-1][j-1]+1，代表把这个字符从两个字符串中去掉后的LCS长度在加上这个字符长度之和。
当text1[i]与text2[j]不同时，那么就要分别去掉这两个字符串的最后一个字符，看看哪个LCS子问题的长度大，选择较大的那个（这里也是区别最长公共子串的点，最长公共子串这里要设置0，代表相等的状态已经断掉，而LCS可以继续保持先前的相等状态）（至于一般动态规划的“取与不取”也在这里，就是取这两个字符串的最后一个字符中的一个，哪个能得到最值解）。
边界就是二维数组的长度就是这两个字符串的长度，比较容易看。
计算顺序从小到大迭代即可，也可以递归从大到小。
*/


// 执行用时：12 ms, 在所有 C++ 提交中击败了99.64%的用户
// 内存消耗：10.4 MB, 在所有 C++ 提交中击败了83.11%的用户
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int size1 = text1.size();
        int size2 = text2.size();
        int dp[size1+1][size2+1];
        
        memset( dp, 0, sizeof(int) * (size1+1) * (size2+1) );
        
        int max_value = 0;
        for ( int i = 1; i <= size1; i++ ){
            for (int j = 1; j <= size2; j++ ){
                if ( text1[i-1] == text2[j-1] ){    //字符串索引要-1
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max( dp[i-1][j], dp[i][j-1] );
                }
                max_value = max_value >= dp[i][j] ? max_value : dp[i][j];
            }
        }
        
        return max_value;
    }
};

