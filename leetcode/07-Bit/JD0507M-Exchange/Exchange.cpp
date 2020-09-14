/**
 * 1. 使用0101与num，获取奇数位
 * 2. 使用1010与num，获取偶数位
 * 3. 左移奇数位，右移偶数位，或运算
 * 
class Solution {
public:
    int exchangeBits(int num) {
        int mask_odd = 0x55555555;
        int mask_even = 0xAAAAAAAA;
        
        int num_odd = num & mask_odd;
        int num_even = num & mask_even;
        
        return (num_odd << 1) | (num_even >> 1);
    }
};