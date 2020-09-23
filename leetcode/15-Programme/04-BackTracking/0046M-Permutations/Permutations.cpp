class Solution {
public:
    // 回溯
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> track;
        
        bt( ans, track, nums, 0, nums.size() );
        
        return ans;
    }
    
    void bt( vector<vector<int>> & ans, vector<int> & track, vector<int> & nums, int first, int len ){
        if ( first == len ){
            ans.emplace_back( track );
        } else {
            for ( int i = first; i < len; i++ ){
                track.emplace_back( nums[i] );
                swap( nums[i], nums[first] );
                first++;
                
                bt( ans, track, nums, first, len );
                
                track.pop_back();
                first--;
                swap( nums[i], nums[first] );
            }
        }
    }
};