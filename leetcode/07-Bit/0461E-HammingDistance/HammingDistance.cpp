class Solution {
public:
    int hammingDistance(int x, int y) {
        bitset<32> b_d = x ^ y;
        return b_d.count();
    }
};