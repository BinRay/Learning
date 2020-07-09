// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
// 内存消耗：6.1 MB, 在所有 C++ 提交中击败了100.00%的用户
// 1. 在bit序列中找到所有0位置。
// 2. 以此0位置向两侧发散，只要值为1则计数加1。
// 3. 取上述最大值。
class Solution {
public:
    int reverseBits(int num) {
        bitset<64> bt(num);
        int max_count = 0;
        int c = 0;
       
        for ( int i = 0; i <= 63; i++ ){
            if ( !bt.test(i) ) c = count( bt, i );
            max_count = max_count > c ? max_count : c;
        
        }
        return max_count;
    }
    
    // 在值为0的位置向两侧发散
    int count( const bitset<64> &bt, int pointer ){
        int c = 0;
        for ( int i = pointer+1; i <= 63; i++ ){
            if ( bt.test(i) ){
                c++;    
            } else {
                break;
            }
        }
        for (int i = pointer-1; i >=0; i-- ){
            if ( bt.test(i) ){
                c++;    
            } else {
                break;
            }
        }
        c++;
        return c;
    }
};