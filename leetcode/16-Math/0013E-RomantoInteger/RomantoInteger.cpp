class Solution {
public:
    int romanToInt(string s) {
        
        int ans = 0;
        s.push_back( '0' ); // 占位用
        
        for ( int i = 0; i < s.size(); i++ ){
            if ( s[i] == 'I'){
                if ( s[i+1] != 'V' && s[i+1] != 'X' ){
                    ans += 1;
                } else {
                    ans -= 1;
                }
            } else if ( s[i] == 'X'){
                if ( s[i+1] != 'L' && s[i+1] != 'C' ){
                    ans += 10;
                } else {
                    ans -= 10;
                }
            } else if ( s[i] == 'C'){
                if ( s[i+1] != 'D' && s[i+1] != 'M' ){
                    ans += 100;
                } else {
                    ans -= 100;
                }
            } else {
                switch (s[i]){
                    case 'V': ans += 5; break;
                    case 'L': ans += 50; break;
                    case 'D': ans += 500; break;
                    case 'M': ans += 1000; break;
                }
            }
        }
        return ans;
    }
};
