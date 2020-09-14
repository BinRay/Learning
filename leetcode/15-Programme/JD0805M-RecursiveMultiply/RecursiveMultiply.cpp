// 1. 每次递归B都减1，转化成加法
// 2. 注意边界

class Solution {
public:
    int multiply(int A, int B) {
        if ( B <= 0 ){
            return 0;
        } else if ( B == 1 ){
            return A;
        } else {
            return A + multiply( A, B-1 );
        }
    }
};