# official solution
# 贪心算法：找出各个独立区域的最大和，比较这些和
class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        curr_sum = max_sum = -20000000000
        for  i in range( len( nums ) ) :
            curr_sum = max( nums[i], nums[i]+curr_sum );
            max_sum = max( max_sum, curr_sum );
        return max_sum



        