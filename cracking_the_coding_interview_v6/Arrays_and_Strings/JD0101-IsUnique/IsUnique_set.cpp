class Solution {
public:
    bool isUnique(string astr) {
        if ( astr.empty() ) {
            return true;
        }
        // 1. 使用set 记录字符是否出现过
        set<char> s;
        for ( auto it = astr.begin(); it != astr.end(); it++ ){
            if ( s.count(*it) > 0 ){
                return false;
            } else {
                s.insert(*it);
            }
        }
        return true;
       
    }
};