class Solution:
    def countPrimes(self, n: int) -> int:
        if n < 2:
            return 0
        arr = [True] * (n)
        arr[0] = arr[1] = False
        import math
        for i in range(2, int(math.sqrt(n)) + 1):
            if arr[i]:
                #第一次知道這個不只能跳著讀還能跳著改......
                arr[i+i::i] = [False] * len(arr[i+i::i])
        return arr.count(True)
