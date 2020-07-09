class Solution {
public:
    string printBin(double num) {
        
        if( num > 1 || num < 0 ){
            return "ERROR";
        }
        
        string s("0.");
        while ( num > 0 ){
            if ( s.size() > 32 ){
                return "ERROR";
            }
            num *= 2;
            if( num >=1 ){
                s += "1";
                num -= 1;
            } else {
                s += "0";
            }
            
        }
        
        return s;
    }
};