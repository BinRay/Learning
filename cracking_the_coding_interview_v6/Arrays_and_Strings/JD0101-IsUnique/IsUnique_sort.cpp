// (0 ms, 100%) (6.1MB, 100%)
class Solution {
public:
    bool isUnique(string astr) {
        if ( astr.empty() ) {
            return true;
        }
        // 1. 排序
        // 2. 比较相邻元素是否相同
        sort ( astr.begin(), astr.end() );
        for ( auto it = astr.begin()+1; it != astr.end(); it++ ){
            if ( *it == *(it-1) ){
                return false;
            }
        }
        return true;
    }
};