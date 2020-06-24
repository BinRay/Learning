// (0 ms, 100%) (6.1MB, 100%)
class Solution {
public:
    bool isUnique(string astr) {
        if ( astr.empty() ) {
            return true;
        }
        // 1. 使用map 记录字符是否出现过
        map<char, bool> m;
        for ( auto it = astr.begin(); it != astr.end(); it++ ){
            if ( m[*it] == true ){
                return false;
            } else {
                m[*it] = true;
            }
        }
        return true;
       
    }
};