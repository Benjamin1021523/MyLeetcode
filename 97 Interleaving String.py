class Solution:
    def isInterleave(self, s1, s2, s3):
        if len(s1) + len(s2) != len(s3):
            return False
        if len(s1) == 0:
            return s2 == s3
        if len(s2) == 0:
            return s1 == s3

        re = False
        if not(re) and s1[0] == s3[0] and s1[-1] == s3[-1]:
            re = re or self.isInterleave(s1[1:-1], s2, s3[1:-1])
        if not(re) and s2[0] == s3[0] and s2[-1] == s3[-1]:
            re = re or self.isInterleave(s2[1:-1], s1, s3[1:-1])
        if not(re) and s1[0] == s3[0] and s2[-1] == s3[-1]:
            re = re or self.isInterleave(s1[1:], s2[:-1], s3[1:-1])
        if not(re) and s2[0] == s3[0] and s1[-1] == s3[-1]:
            re = re or self.isInterleave(s1[:-1], s2[1:], s3[1:-1])
        return re