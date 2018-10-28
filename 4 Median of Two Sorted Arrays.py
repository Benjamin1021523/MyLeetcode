class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        target = (len(nums1) + len(nums2)) / 2
        j = k = 0
        re = 1.0
        while j + k < target:
            if j == len(nums1):
                re = nums2[k]
                k += 1
            elif k == len(nums2):
                re = nums1[j]
                j += 1
            else:
                if nums1[j] < nums2[k]:
                    re = nums1[j]
                    j += 1
                else:
                    re = nums2[k]
                    k += 1
        if (len(nums1) + len(nums2)) % 2:
            return re
        else:
            if j == len(nums1):
                return (re * 1.0 + nums2[k]) / 2
            elif k == len(nums2):
                return (re * 1.0 + nums1[j]) / 2
            else:
                if nums1[j] < nums2[k]:
                    return (re * 1.0 + nums1[j]) / 2
                else:
                    return (re * 1.0 + nums2[k]) / 2