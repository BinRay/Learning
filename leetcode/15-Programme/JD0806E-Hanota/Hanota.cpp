/**
 * 简化问题规模，将一个大问题分解成若干小问题，假设一个有n个圆盘
    1. 将A上的n-1个圆盘，放到B上。
    2. 将A上的最后一个圆盘放到C上。
    3. 将B上的n-1个圆盘放到C上。
    4. 注意边界。

*/

class Solution {
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        if ( A.size() == 0 ) return;
        move ( A, B, C, A.size() );
    }
    
    void move( vector<int>& A, vector<int>& B, vector<int>& C, int n ){
        if ( n == 1 ){
            int largest = A.back();
            A.pop_back();
            C.push_back( largest );
        } else {
            move ( A, C, B, n-1 );
            
            int largest = A.back();
            A.pop_back();
            C.push_back( largest );
            
            move ( B, A, C, n-1 );
        }
    }
};