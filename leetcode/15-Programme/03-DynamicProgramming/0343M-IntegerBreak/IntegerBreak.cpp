// 子问题：n = a + b
class Solution {
public:
    int integerBreak(int n) {
        vector<int> opt;    // 保存以n为下标拆分出的两个正整数最大乘积。
        opt.push_back( 0 ); // 占位
        opt.push_back( 1 ); // 1本身能达到的最大乘积值
        opt.push_back( 1 ); // 2
        
        for ( int i = 3; i <= n; i++ ){
            int max_multiply = 0;
            for ( int j = 1; j <= i / 2; j++ ){
                int a = j;
                int b = i-a > 3 ? opt[i-a] : i-a; // 拆分的数如果小于4，则乘积最大值是它自己
                max_multiply = max( max_multiply, a * b );
            }
            opt.push_back( max_multiply );
        }
        return opt.back();
    }
};