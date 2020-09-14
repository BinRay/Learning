class Solution {
public:
    int waysToStep(int n) {
        if ( n < 1 ) return 1;
        if ( n == 1 ) return 1;
        if ( n == 2 ) return 2;
        if ( n == 3 ) return 4;
        
        long a = 1;
        long b = 2;
        long c = 4;
        
        long sum = 0;
        for ( int i = 4; i <= n; i++ ){
            sum = (a + b + c) % 1000000007;
            a = b;
            b = c;
            c = sum;
        }
        
        return sum ;
            
    }
};