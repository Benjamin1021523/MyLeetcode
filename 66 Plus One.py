class Solution:
    def plusOne(self, digits):
        num = int("".join(str(x) for x in digits))+1
        num = [int(x) for x in str(num)]
        return num