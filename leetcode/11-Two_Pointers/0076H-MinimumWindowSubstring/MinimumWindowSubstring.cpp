#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {

        // distance用于表明s的候选子串与目标串t的编辑距离，初始值为t的长度
        int distance = t.size();

        // 下面两个表用于记录s的子串、t中各字符出现的频数。
        unordered_map<char, int> s_table;
        unordered_map<char, int> t_table;

        for ( auto c: t ){
            t_table[c]++;
        }

        // 滑动窗口的左右指针，左闭半开，right-left代表窗口的长度
        int left = 0;
        int right = 0;

        // 符合要求的S子串的长度及位置
        int sub_len = s.size()+1;
        int sub_first = 0;

        while ( right <= s.size() ){

            // distance等于0代表已经找到一个符合要求的子串
            if ( distance == 0 ){
                if ( right - left < sub_len ){
                    sub_len = right - left;
                    sub_first = left;
                }

                // 即将缩小窗口，计算缩小之后的距离distance
                if ( t_table.count(s[left]) && s_table[s[left]] == t_table[s[left]] ){
                    distance++; //减少了一个关键字符，距离加1
                }

                // 缩小窗口，子串对应字符的频数减1.
                s_table[s[left]]--;
                left++;

            } else {
                if ( right >= s.size() ) break;

                // 增加的字符
                char new_c = s[right];
                // 扩大窗口
                right++;

                if ( t_table.count( new_c ) && s_table[new_c] < t_table[new_c] ){
                    distance--;
                }

                s_table[new_c]++;   // 子串对应频数加1
            }
        }

        // 判断是否找到覆盖子串
        if ( sub_len <= s.size() ){
            string sub( s.begin() + sub_first, s.begin() + sub_first + sub_len );
            return sub;
        } else {
            return "";
        }

    }
};

int main( int argc, char* argv[] ){
    Solution so;
    // string s("ADOBECODEBANC");
    // string t("ABC");
    string s("AAA" );
    string t( "AA" );
    so.minWindow( s, t );
    return 0;
}