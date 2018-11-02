class Solution:
    def isLongPressedName(self, name, typed):
        r = 0
        for i in range(len(typed)):
            if typed[i] == name[r]:
                r += 1
            if r == len(name):
                return True
        return False