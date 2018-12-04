class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        dict = {}
        for i in range(len(nums)):
            if nums[i] in dict and target == nums[i] * 2:
                return [dict[nums[i]], i]
            else:
                dict[nums[i]] = i
        for i in dict:
            #leetcode的環境有點怪，字典會自行排序，其他環境可能錯誤
            #if target - i in dict and i != target - i:
            if target - i in dict:
                return [dict[i], dict[target - i]]