class Solution {
public:
    int convertInteger(int A, int B) {
        int count = 0;
        bitset<32> a(A);
        bitset<32> b(B);
        
        for ( int i = 0; i < 32; i++ ){
            count = a[i] != b[i] ? count + 1 : count;
        }
        
        return count;
    }
};