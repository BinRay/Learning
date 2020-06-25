class Solution {
public:
    string compressString(string S) {
        if ( S.size() == 0 ){
            return S;
        }
        
        char last_char = S.at(0);
        int last_count = 1;
        string new_s;
        
        // 1. 注意要从1位置起
        for ( auto it = S.begin()+1; it != S.end(); it++ ){
            if ( *it == last_char ){
                last_count++;
            } else {
                new_s += last_char;
                new_s += to_string(last_count);
                
                last_char = *it;
                last_count = 1;
            }
        }
        
        new_s += last_char;
        new_s += to_string(last_count);
        
        return S.size() > new_s.size() ? new_s : S;
        
    }
};