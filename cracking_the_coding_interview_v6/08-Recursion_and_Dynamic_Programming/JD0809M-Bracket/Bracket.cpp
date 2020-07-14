
// 时间较慢在于每次调用剪枝函数，其实使用左括号/右括号计数判断更好。另外map也有点杀鸡用牛刀了。
// 执行用时：32 ms, 在所有 C++ 提交中击败了5.54%的用户
// 内存消耗：9.2 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
private:
    vector<string> permutations;
    int len;
    
public:
    vector<string> generateParenthesis(int n) {
        len = 2 * n;
        unordered_map<char, int> m;
        m['('] = 0;
        m[')'] = 0;
        for ( int i = 0; i < n; i++ ){
            m['(']++;
            m[')']++;
        }
        
        backtrack( "", m );
        return permutations;
    }
    
    void backtrack( string prefix, unordered_map<char, int> m ){
        if ( prefix.size() == len ){
            permutations.push_back( prefix );
            return;
        }
        
        for ( unordered_map<char,int>::iterator it = m.begin(); it != m.end(); it++ ){
            if ( it -> second ){
                if ( is_valid_parenthesis( prefix + it -> first ) ){    // 剪枝
                    ( it -> second )--;
                    backtrack( prefix + it -> first, m );
                    ( it -> second )++;
                    
                }
            }
        }
    }
    
    bool is_valid_parenthesis( string s ){
        int count = 0;
        for ( auto c: s ){
            if ( c == '(' ){
                count++;
            } else {
                if ( !count ){
                    return false;
                } else {
                    count--;
                }
            }
        }
        return true;
    }
    
};

