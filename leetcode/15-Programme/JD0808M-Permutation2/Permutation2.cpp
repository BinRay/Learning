/**
 * 1. 使用map记录字符串中各字符出现次数。
 * 2. 回溯法：
 *      1. 选择字符，并将其次数减1.
 *      2. 判定是否达到终止条件
 *      3. 次数加1，复原
 */


// 执行用时：4 ms, 在所有 C++ 提交中击败了94.51%的用户
// 内存消耗：7.2 MB, 在所有 C++ 提交中击败了100.00%的用户
class Solution {
public:
    vector<string> permutation(string S) {
        unordered_map<char, int> m;
        for( auto c: S ){
            if ( m.count(c) ){
                m[c]++;
            }else {
                m[c] = 1;
            }
        }
        
        vector<string> permutations;
        backtrack( permutations, m, "", S.size() );
        return permutations;
    }
    
    void backtrack( vector<string> &permutations, unordered_map<char, int> &m, string prefix, const int len ){
        if ( prefix.size() == len ){
            permutations.push_back( prefix );
            return;
        }
        
        for ( unordered_map<char, int>::iterator it = m.begin(); it != m.end(); it++ ){
            if ( it -> second ){
                //cout << it->first << " " << it->second << " " << prefix << endl;
                (it -> second)--;                                           // 选择 
                backtrack( permutations, m, prefix + it->first, len );      // 递归判定
                (it -> second)++;                                           // 回溯
            }
        }
    }
};

