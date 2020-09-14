/** 
1. 较大：从右向左找到第一个“01”，将其置换成“10”，并将其右侧所有的1尽可能向后移动。
    1. 找到01位置，记做p_larger.
    2. 将p_larger右侧所有bit置为0.
    3. 计算num在p_larger右侧有多少1.
    4. 将这些1后移。
    5. 置换01为10，得到较大数。
2. 较小：从右向左找到第一个“10”，换成“01”，并将其右侧所有1尽可能靠前移动。
    1. 找到10位置，记做p_smaller.
    2. 将p_smaller右侧所有bit置为0.
    3. 计算num在p_smaller右侧有多少1.
    4. 将这些1前移。
    5. 置换10为01，得到较小数。
*/
class Solution {
public:
    vector<int> findClosedNumbers(int num) {
        vector<int> v;
        const int len = 31; 
        bitset<len> b(num);
        int count = b.count();
        
        // 较大
        int p_larger = -1;
        for ( int i = 0; i < len-1; i++ ){
            if ( b.test(i) && !b.test(i+1) ){
                p_larger = i;               // 找到01位置
                break;
            }
        }
        if ( p_larger == -1 ){
            v.push_back( -1 );              // 没有代表是最大的数字
        } else {
            bitset<len> b_larger = b;
            bitset<len> mask = pow( 2, p_larger ) - 1;   // 处理右侧bit，形如0000011111
            
            mask.flip();                // 1111100000     
            b_larger &= mask;           // reset右侧所有bit
    
            mask.flip();                // 0000011111
            mask &= b;
            int count = mask.count();   // 计算01右侧有有多少个1 
            
            mask = pow( 2, count ) - 1;   // 将所有1靠后
            
            b_larger[p_larger] = 0;
            b_larger[p_larger+1] = 1;          // 置换
    
            b_larger |= mask;           
            v.push_back( b_larger.to_ulong() );
            
        }
        
        // 较小
        int p_smaller = -1;
        for ( int i = 0; i < len-1; i++ ){
            if ( !b.test(i) && b.test(i+1) ){
                p_smaller = i;               // 找到10位置
                break;
            }
        }
        if ( p_smaller == -1 ){
            v.push_back( -1 );              
        } else {
            bitset<len> b_smaller = b;
            bitset<len> mask = pow( 2, p_smaller ) -1;
            
            mask.flip();
            b_smaller &= mask;
            
            mask.flip();
            mask &= b;
            int count = mask.count();
            
            mask = pow( 2, count ) -1;
            mask <<= p_smaller - count;     // 将1靠前
            
            b_smaller[p_smaller] = 1;
            b_smaller[p_smaller+1] = 0;
            
            b_smaller |= mask;
            v.push_back( b_smaller.to_ulong() );
            
        }
        
        return v;
    }
};