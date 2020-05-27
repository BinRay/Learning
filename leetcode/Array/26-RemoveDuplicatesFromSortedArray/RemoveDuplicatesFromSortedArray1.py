class Solution:
    def removeDuplicates(self, nums):
        if len(nums) == 0:
            return 0
        
        base = 1
        explorer = 1
        length = len(nums)

        while explorer < length:
            if nums[ explorer ] != nums[ explorer-1 ]:
                nums[ base ] = nums [ explorer ]
                base+=1
            explorer+=1
        
        return base


nums = [1, 2, 3, 3, 3, 4, 4, 5, 70, 70, 72, 75, 100, 200, 200, 300]
s = Solution()
s.removeDuplicates( nums )
print( nums )