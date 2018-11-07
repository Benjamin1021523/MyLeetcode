class Solution:
    def isNumber(self, s):
        import re
        re = re.compile("^[+-]?(([0-9]+\\.?[0-9]*)|(\\.[0-9]+))(e[+-]?[0-9]+)?$")
        result = re.search(s.strip())
        return result != None