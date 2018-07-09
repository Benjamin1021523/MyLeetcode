class Solution:
    def transpose(self, A):
        '''ans = []
        for i in range(len(A[0])):
            ans.append([])
            for j in range(len(A)):
                ans[i].append(A[j][i])
        return ans'''
        return list(map(list, zip(*A)))