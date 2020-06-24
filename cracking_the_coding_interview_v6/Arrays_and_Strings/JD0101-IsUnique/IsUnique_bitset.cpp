// (0 ms, 100%) (5.9MB, 100%)
class Solution {
public:
    bool isUnique(string astr) {
        if ( astr.empty() ) {
            return true;
        }
        // 1. 使用bieset 记录字符是否出现过
        bitset<128> bs;
        for ( auto it = astr.begin(); it != astr.end(); it++ ){
            if ( bs[*it] == true ){
                return false;
            } else {
                bs[*it] = true;
            }
        }
        return true;
       
    }
};