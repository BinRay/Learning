// 双指针:
// 1. first表示待插入非零元素的位置，second表示正在扫描的位置。
// 2. second扫描后，将末尾的元素填充0。

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        vector<int>::iterator first = nums.begin();
        vector<int>::iterator second = nums.begin();
        
        for ( ; second != nums.end(); second++ ) {
            if ( *second == 0 ){
                continue;
            } else {
                *first = *second;
                first++;
            }
        }
        
        if ( first != second ){
            fill( first, nums.end(), 0 );
        }
        
        
        
    }
};