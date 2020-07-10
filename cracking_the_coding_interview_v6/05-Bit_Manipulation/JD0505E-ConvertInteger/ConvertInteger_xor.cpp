class Solution {
public:
    int convertInteger(int A, int B) {
        bitset<32> diff = A ^ B;
        return diff.count();
    }
};