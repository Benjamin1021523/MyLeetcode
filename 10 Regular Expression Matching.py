class Solution:
    def isMatch(self, s, p):
        import re
        result = re.match("^"+p+"$", s)
        #print(result)
        return result != None