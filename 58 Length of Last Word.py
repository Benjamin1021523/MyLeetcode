class Solution:
    def lengthOfLastWord(self, s):
        import re
        m = re.findall('[a-zA-Z]+', s)
        if len(m) == 0:
            return 0
        return len(m[-1])