class Solution {
    public boolean isValid(String s) {
        int[] array = new int[s.length()];

        boolean ans = true;
        int nowDepth = -1;
        for (char c : s.toCharArray()) {
            if (!ans) break;
            switch (c) {
                case 'a':
                    array[++nowDepth] = 1;
                    break;
                case 'b':
                    if (nowDepth == -1) {
                        ans = false;
                    } else if (array[nowDepth] == 1) {
                        array[nowDepth] = 2;
                    } else {
                        ans = false;
                    }
                    break;
                case 'c':
                    if (nowDepth == -1) {
                        ans = false;
                    } else if (array[nowDepth] != 2) {
                        ans = false;
                    } else {
                        nowDepth--;
                    }
                    break;
                default:
                    break;
            }
        }
        return ans && nowDepth == -1;
    }
}