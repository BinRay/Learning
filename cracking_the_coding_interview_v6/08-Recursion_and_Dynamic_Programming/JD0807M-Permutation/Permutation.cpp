/** 
 * 1. 用S构建一个字符集合
 * 2. 假设S共有N个元素，取其中的每个元素
 * 3. 将剩余的N-1个元素排列，并将2中取出的元素放到所有N-1字符串排列的末尾，构成新的集合。
 * 4. 合并2中所有N个元素的情况。
 * 5. 注意边界
*/


class Solution {
public:
    vector<string> permutation(string S) {
        
        vector<string> strs;
        unordered_set<char> s( S.begin(), S.end() );
        strs = dc( s );
        return strs;
        
    }
    
    vector<string> dc ( const unordered_set<char> &s ){
        if ( s.empty() ){
            return { "" };
        } else {
            vector<string> strs;
            for ( auto c: s ){
                unordered_set<char> sub_set = s;
                sub_set.erase( c );
                vector<string> sub_strings = dc( sub_set );
                for ( auto sub_string: sub_strings ){
                    sub_string += c;
                    strs.push_back( sub_string );
                }
            }
            return strs;
        }
        
    }

};