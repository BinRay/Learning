class Solution {
public:
    int jump(vector<int>& nums) {
        // 动态规划，是个n2解。迭代计算到达每个元素的最小步数。
        
        if ( nums.empty() ) return 0;
        
        // 本解采用贪心算法
        int farthest = 0;   // 迭代过程中所能跳跃的最远距离
        int end = 0;        // 每步所能跳达的边界
        int jumps = 0;      // 跳跃数
        
        for ( int i = 0; i < nums.size() - 1; i++ ){
            farthest = farthest < nums[i] + i ? nums[i] + i : farthest;
            
            
            if ( i == end ){
                jumps++;
                end = farthest;     // 下一步的边界
            }
            
        }
        
        return jumps;
        
    }
};
