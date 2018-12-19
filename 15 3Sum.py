class Solution:
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        leng = len(nums)
        re = []
        if leng > 2:
            for i in range(leng-2):
                if nums[i] > 0:
                    break;
                if i != 0 and nums[i] == nums[i-1]:
                    continue;
                l = i + 1
                r = leng - 1
                while l < r:
                    if nums[i] + nums[l] + nums[r] == 0:
                        re.append([nums[i], nums[l], nums[r]])
                        while l < r and nums[l] == nums[l+1]:
                            l += 1
                        while l < r and nums[r] == nums[r-1]:
                            r -= 1
                        l += 1
                        r -= 1
                    elif nums[i] + nums[l] + nums[r] > 0:
                        r -= 1;
                    else:
                        l += 1
        return re