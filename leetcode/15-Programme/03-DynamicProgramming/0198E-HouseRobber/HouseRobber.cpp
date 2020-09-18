class Solution {
public:
    int rob(vector<int>& nums) {
        if ( nums.size() == 0 ){
            return 0;
        }
        
        if ( nums.size() == 1 ) {
            return nums[0];
        }
        
        if ( nums.size() == 2 ){
            return max( nums[0], nums[1] );
        }
        
        vector<int> opt;
        opt.push_back( nums[0] );
        opt.push_back( max( nums[0], nums[1] ) );
        
        for ( int i = 2; i < nums.size(); i++ ){
            opt.push_back( max( opt[i-2] + nums[i], opt[i-1] ) );
        }
        
        return opt.back();
        
        
    }
};