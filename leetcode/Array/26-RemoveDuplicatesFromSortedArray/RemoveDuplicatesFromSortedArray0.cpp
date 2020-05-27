#include <vector>
#include <iostream>

using namespace std;

// O(n2), compare index and index+1, if equivalent, move index+1 to the last. like bubble. This solution will cause time limit exceeded.
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if ( nums.size() == 0){
            return 0;
        }

        int index = 0;
        int last = nums.size() - 1;
        while ( index != last ){
            while( nums[ index ] == nums[ index+1 ] ) {
                move( index+1, last, nums );
            }
            index++;
        }
        return index + 1;
    }

private:
    void swap( int i, int j, vector<int>& nums ){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    void move( int i, int& last, vector<int>& nums){
        while ( i < last ){
            swap( i, i+1, nums);
            i++;
        }
        last--;
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