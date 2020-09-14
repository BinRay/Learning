// 一次编辑
// (0ms, 100%) (6.4MB, 100%)
class Solution {
public:
    bool oneEditAway(string first, string second) {
        if ( first == second ){
            return true;
        }
        int diff = first.size() - second.size();
        if ( abs( diff ) > 1 ){
            return false;
        }

        // 1. 在字符串不相等，且长度只相差1的前提下
        // 2. 识别两个字符串哪个较长，并使用双指针从前后扫描两个字符串
        // 3. (a)如果长度相同，只有一处不同，则最后一定前后扫描一定停在不同的位置处。
        // 4. (b)如果长度不同，只多一个字符，对于较的长字符串来说，从后扫描一定会越过或停在从前扫描停住的位置。
        // 5. (b-1) 停住情况（it1=it2）：first = "123a456", second = "123456"
        // 6. (b-2) 越过情况（it1>it2）: first = "12344456", second = "1234456"
        string *long_string, *short_string;
        long_string = diff >= 0 ? &first : &second;
        short_string = diff >= 0 ? &second : &first;
        
        auto it1 = long_string -> begin();
        auto it2 = long_string -> end() - 1;

        for ( auto c: *short_string ){  
            if ( *it1 != c ){
                break;
            }
            it1++;
        }      
        
        for ( int i = short_string->size() - 1; i >= 0; i--, it2-- ){
            if ( *it2 != short_string->at(i) ){
                break;
            }
        }
        return it2 <= it1;
    }
};