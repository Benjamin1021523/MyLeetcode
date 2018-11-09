class Solution:
    def subsets(self, nums):
        re = []
        for i in range(1 << len(nums)):
            re.append([])
            for j in range(len(nums)):
                if i & (1 << j):
                    re[-1].append(nums[j])
        return re