class Solution {
public:
    // 利用掩码，位操作运算
    int insertBits(int N, int M, int i, int j) {
        
        bitset<32> b_N( N );
        bitset<32> b_M( M );
        
        bitset<32> mask;
        mask.set();
        mask <<= j-i+1;
        
        mask.flip();
        mask <<= i;
        mask.flip();
        b_N &= mask;
        
        b_M <<= i;
        b_N |= b_M;
        
        return b_N.to_ulong();
    }
};