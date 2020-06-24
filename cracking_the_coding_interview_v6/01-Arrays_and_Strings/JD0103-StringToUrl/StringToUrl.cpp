// URL化
// (72ms, 79.23%) (20.6MB, 100%)
class Solution {
public:
    string replaceSpaces(string S, int length) {
        // 1. 遍历字符串，计算空格数。
        // 2. 重新调整字符串，避免越界。
        // 3. 倒序遍历，判断是否为空格，并将相应字符（串）插入。
        int blank_size = 0;
        for ( int i = 0; i < length; i++ ){
            if ( S[i] == ' ' ){
                blank_size++;
            }
        }
        
        int resize_length = length + blank_size * 2;
        S.resize( resize_length );
        for ( int index = length-1, index_r = resize_length; index >=0; index-- ){
            if ( S[index] == ' ' ){
                S[--resize_length] = '0';
                S[--resize_length] = '2';
                S[--resize_length] = '%';
            } else {
                S[--resize_length] = S[index];
            }
        }
        
        return S;
    }
};