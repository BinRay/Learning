class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        // 前缀和数组
        int pre[n+1];
        pre[0] = 0;
        
        int ans = 0;
        
        for ( int i = 0; i < n; i++ ){
            pre[i+1] = pre[i] + nums[i];
        }
        
        for ( int i = 0; i < n; i++ ){
            for ( int j = i + 1; j <= n; j++ ){
                // [i, j) 区间的和
                if ( pre[j] - pre[i] == k )
                    ans++;
            }
        }
        
        return ans;
    }
};
