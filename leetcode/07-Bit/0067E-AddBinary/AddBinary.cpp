#include <iostream>
#include <string>
#include <bitset>
#include <algorithm>

using namespace std;

// 通过“异或”和“移位”模拟加法
// 借助bitset
class Solution {
public:
    string addBinary(string a, string b) {
        // len必须是常量
        const int len = 128;
        bitset<len> bs_a(a);
        bitset<len> bs_b(b);
        bitset<len> bs_zero;
        bitset<len> carry;

        while ( bs_b != bs_zero ){
            carry = (bs_a & bs_b) << 1;
            bs_a ^= bs_b;
            bs_b = carry;
        }
  
        string s = bs_a.to_string();
        auto it = find( s.begin(), s.end(), '1' );
        string s_new(it, s.end());
        return bs_a==bs_zero ? "0" : s_new;
    }
};

int main( int argc, char** argv ){
    Solution s;
    cout <<  s.addBinary( "010" , "110");
}
