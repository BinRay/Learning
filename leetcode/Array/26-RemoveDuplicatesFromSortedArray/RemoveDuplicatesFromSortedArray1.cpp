#include <vector>
#include <iostream>

using namespace std;

// O(n) 用一个探路者索引去找不重复的元素，留一个基地索引用于存储不重复的元素。探路者只需O(1)即可找到所有不重复元素。
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if ( nums.size() == 0){
            return 0;
        }

        int base = 1;
        int explorer = 1;
        int length = nums.size();
        for ( ; explorer < length; explorer++ ){
            if ( nums[ explorer ] != nums[ explorer-1 ] ){
                nums[ base++ ] = nums[ explorer ];
            }
        }
        return base;
    }
};

int main( int argc, char** argv ){
    vector<int> nums = { 1, 1, 2, 2, 3, 3, 3, 5, 6, 8, 8, 20, 100 };
    Solution s;
    s.removeDuplicates( nums );
    for ( auto& i: nums ){
        cout << i << " ";
    }
}