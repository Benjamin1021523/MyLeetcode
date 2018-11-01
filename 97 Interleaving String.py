class Solution:
    def isInterleave(self, s1, s2, s3):
        if len(s1) + len(s2) != len(s3):#長度不對
            return False
        if not(len(s1)) or not(len(s2)):#其中一個是空字串
            return s1 + s2 == s3

        d_s1 = [True]
        for i in range(1, len(s1)+1):#把s1和s3從頭比對連續幾個相同
            if not(d_s1[i-1]):
                break;
            d_s1.append(s1[i-1] == s3[i-1])
        while len(d_s1) < len(s1)+1:#末端補0
            d_s1.append(False)

        d_s2 = [True]
        for i in range(1, len(s2)+1):#把s2和s3從頭比對連續幾個相同
            if not(d_s2[i-1]):
                break;
            d_s2.append(s2[i-1] == s3[i-1])
        while len(d_s2) < len(s2)+1:#末端補0
            d_s2.append(False)

        dp = [d_s2]
        for i in range(1, len(d_s1)):#手動產生二維陣列
            dp.append([d_s1[i]])
            for j in range(1, len(d_s2)):
                dp[i].append((dp[i-1][j] and s3[i+j-1] == s1[i-1]) or
                             (dp[i][j-1] and s3[i+j-1] == s2[j-1]))

        return dp[len(dp)-1][len(dp[0])-1]