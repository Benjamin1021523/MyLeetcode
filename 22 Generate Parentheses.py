class Solution:
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        re = []
        def f(pre, l):
            if l == n:
                re.append(pre + ')' * (2 * n - len(pre)))
                return 0
            while len(pre) <= 2 * l:
                f(pre + '(', l + 1)
                pre += ')'
        f("", 0)
        return re