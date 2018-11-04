#這題python先做出來
#負的索引值真是太方便看了
class Solution:
    def rotate(self, matrix):
        l = len(matrix)
        for i in range(int(l / 2)):
            for j in range(i, l-i-1):
                temp = matrix[i][j]
                matrix[i][j] = matrix[-j-1][i]
                matrix[-j-1][i] = matrix[-i-1][-j-1]
                matrix[-i-1][-j-1] = matrix[j][-i-1]
                matrix[j][-i-1] = temp