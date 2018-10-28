class Solution:
    def __init__(self):
        self.out = []
        self.ins = ""
        self.table = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
    def _get(self, s, index):
        if index == len(self.ins):
            self.out.append(s);
        else:
            for i in range(len(self.table[ord(self.ins[index]) - ord('0')])):
                self._get(s + self.table[ord(self.ins[index]) - ord('0')][i], index + 1)
    def _getstr(self):
        self._get("", 0);

    def letterCombinations(self, digits):
        if digits == "":
            return self.out
        self.ins = digits
        self._getstr()
        return self.out