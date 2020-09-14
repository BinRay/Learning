/** 
 * 
 * 执行用时：8 ms, 在所有 C++ 提交中击败了30.66%的用户
 * 内存消耗：7.7 MB, 在所有 C++ 提交中击败了100.00%的用户
 
### 解题思路
1. 非线段行（即高度与y不等）填充0即可。
2. 对于含有线段行
    1. 确定32位为1个窗口，计算左边界和有边界（左封右开）位置。
    2. 线段起始点与窗口边界比较。
    3. 计算窗口内的数值，并加入vector中。
    4. 注意起始点都在同一个窗口或起始点在窗口外的情况。

*/

class Solution {
public:
    vector<int> drawLine(int length, const int w, int x1, int x2, int y) {
        vector<int> row;
   
        // 不确定x1和x2哪个大
        int p_right = x1 > x2 ? x1 : x2;    // 右点位置
        int p_left = x1 > x2 ? x2 : x1;     
        
        // 非线段行插入0
        for ( int h = 0; h != y; h++ ){
            for ( int i = 0; i < w / 32; i++ ){
                row.push_back( 0 );
            }
        }
        
        // 处理线段行：从左往右扫描，以32位为一个单元
        for ( int bound = 0; bound < w; bound += 32 ){
            if ( p_left >= bound + 32 ){                            // 线段在窗口之外
                row.push_back( 0 );
            } else if ( p_right < bound ) {                         // 线段在窗口之外
                row.push_back( 0 );
            } else if ( p_left >= bound && p_right < bound +32 ){ // p_left和p_right在同一个整数中
                bitset<32> num;
                int len = p_right - p_left + 1;
                num.flip();
                num >>= len;
                num.flip();
                int shift = p_left % 32;
                num >>= shift;
                row.push_back( num.to_ulong() );
            } else if ( bound > p_left && bound + 32 <= p_right ){  // 中间是-1(32个1)，起始点都在窗口之外
                row.push_back( -1 );
            } else if ( p_left < bound + 32 && p_left >= bound ){   // 左点在窗口中
                bitset<32> num;
                int shift = p_left % 32;
                num.set();
                num >>= shift;
                row.push_back( num.to_ulong() );
            } else if ( p_right >= bound && p_right < bound + 32 ){ // 右点在窗口中
                bitset<32> num;
                int shift = p_right % 32 + 1;
                num.set();
                num >>= shift;
                num.flip();
                row.push_back( num.to_ulong() );
            } else {
                cout << "can't reanch here" << endl;
            }
        }
        
        // 非线段行插入0
        for ( int h = y + 1; h < length * 32 / w; h++ ){
             for ( int i = 0; i < w / 32; i++ ){
                row.push_back( 0 );
            }
        }
        
        return row;
    }
};
