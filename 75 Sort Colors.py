class Solution:
    def sortColors(self, nums):
        cnt = [0,0,0]
        for i in nums:
            cnt[i] += 1

        for i in [0,1,2]:
            nums += [i] * cnt[i]
        del nums[:int(len(nums)/2)]