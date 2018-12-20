class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        if len(s) < 2:
            return len(s)

        cnt = 0;
        for i in range(0, len(s)):
            note = [False]*130
            j = i
            while j < len(s) and not(note[ord(s[j])]):
                note[ord(s[j])] = 1
                j += 1
            if j - i > cnt:
                cnt = j - i
        return cnt