class Solution:
    def swap(self, a, b):
        return b, a
    def sortArrayByParityII(self, A):
        oddi = -1
        eveni = -2
        for i in range(len(A)):
            if not(i % 2 ^ A[i] % 2):
                continue

            while A[eveni] % 2 == 0 and eveni > -len(A):
                eveni -= 2;
            while A[oddi] % 2 == 1 and oddi > -len(A):
                oddi -= 2;

            if i % 2:
                A[i], A[eveni] = self.swap(A[i], A[eveni])
                eveni -= 2
            else:
                A[i], A[oddi] = self.swap(A[i], A[oddi])
                oddi -= 2

        return A