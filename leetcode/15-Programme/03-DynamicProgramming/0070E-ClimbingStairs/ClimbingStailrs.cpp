class Solution {
public:
    int climbStairs(int n) {
        if ( n < 3 ){
            return n == 1 ? 1 : 2;
        }
        int prev1 = 1;
        int prev2 = 2;
        int temp;
        for ( int i = 3; i <= n; i++ ){
            temp = prev1 + prev2;
            prev1 = prev2;
            prev2 = temp;
        }
        return temp;
    }
};