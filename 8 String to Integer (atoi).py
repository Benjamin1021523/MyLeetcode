class Solution:
    def myAtoi(self, str):
        pattern = re.compile(r'^([+-]?0*[0-9]+)')
        str = str.strip()
        m = pattern.match(str)
        if(m == None):
            return 0

        num = int(m.group(1))
        if num > 2147483647:
            return 2147483647
        elif num < -2147483648:
            return -2147483648
        return num