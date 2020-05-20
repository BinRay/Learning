import cProfile
class Solution:
    # 暴力循环：O(n2)
    def twoSum1(self, nums, target):
        for i in range(0, len(nums)):
            for j in range(i+1, len(nums)):
                if nums[i] + nums[j] == target:
                    return [i, j]

    # 使用字典: O(n)
    def twoSum2(self, nums, target):
        temp_map = {}
        for index, value in enumerate(nums):
            another_value = target - value
            if another_value in temp_map:
                return [temp_map[another_value], index]
            else:
                temp_map[value] = index


nums = []
for i in range(1000000):
    nums.append(i)

solution = Solution()
cProfile.run('solution.twoSum2(nums, 800000)')
result = solution.twoSum2([2, 7, 11, 15], 9)
print(result)

