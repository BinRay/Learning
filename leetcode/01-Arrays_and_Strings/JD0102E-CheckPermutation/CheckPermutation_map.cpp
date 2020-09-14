// 判定是否互为字符重拍
// (0, 100%) (6.3MB, 100%)
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if ( s1.size() != s2.size() ){
            return false;
        }
        
        // 1. 使用两个map分别记录s1和s2各字符出现的次数
        // 2. 判断两个map是否相同
        map<char, int> m1;
        map<char, int> m2;
        for ( auto c: s1){
            m1[c]++;
        }
        for ( auto c: s2){
            m2[c]++;
        }
        
        return equal( m1.begin(), m1.end(), m2.begin() );
    }
};