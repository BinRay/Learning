class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort( nums.begin(), nums.end() );
        
        for ( int i = 1; i < nums.size(); i+=2 ){
            swap ( nums[i], nums[i-1] );
        }
    }
};