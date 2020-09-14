class Solution {
public:
    int insertBits(int N, int M, int i, int j) {
        
        bitset<32> b_N( N );
        bitset<32> b_M( M );
        
        for ( int x = i, y = 0 ; x <= j; x++, y++ ){
            b_N[x] = b_M[y];
        }
        
        return b_N.to_ulong();
    }
};