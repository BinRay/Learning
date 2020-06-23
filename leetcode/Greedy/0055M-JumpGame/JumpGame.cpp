// 遍历数组，每次迭代计算处在每个索引时能到达的最远位置，当索引比最远位置大时返回失败，否则遍历完数组返回成功。
class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int can_reach_max = 0;
        for ( int i = 0; i < nums.size(); i++ ){
            if ( i > can_reach_max ){
                return false;
            }
            can_reach_max = can_reach_max > nums[i] + i ? can_reach_max : nums[i] + i ;
            // 这里也可以加一个判定，是否大于最大索引
        }
        return true;
    }
};