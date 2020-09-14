class Solution {
public:
    bool canPermutePalindrome(string s) {
        // 1. 遍历数组，翻转bitset对应位置值
        // 2. 统计最后设置位是否小于等于1
        bitset<128> bs;
        for ( auto c: s ){
            bs.flip(c);
        }
        return bs.count() <= 1;
    }
};