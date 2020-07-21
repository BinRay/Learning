/**
 * 
 * 1. 遍历字符串数组
   2. 对每个字符串排序
   3. 以排序后的字符串作为键，以插入结果vector的索引作为值。
   4. 如果存在于map中，则直接取ans vector的索引，并添加这个vector到vector的末尾。
   5. 否则新建一个vector，并以vector的索引更新map。
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> m;
        vector<vector<string>> ans;
        for ( int i = 0; i < strs.size(); i++ ){
            string ordered_str = strs[i];
            sort( ordered_str.begin(), ordered_str.end() );
            if ( m.count(ordered_str) ){
                ans[m[ordered_str]].push_back( strs[i] );
            } else {
                vector<string> v = { strs[i] };
                ans.push_back( v );
                m[ordered_str] = ans.size()-1;
            }
        }
        return ans;
    }
};

