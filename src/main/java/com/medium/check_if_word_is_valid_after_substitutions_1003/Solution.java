package com.medium.check_if_word_is_valid_after_substitutions_1003;

public class Solution extends AbstractSolution {
    public boolean isValid(String s) {
        int[] array = new int[s.length()];

        boolean ans = true;
        int nowDepth = -1;
        for (char c : s.toCharArray()) {
            if (!ans) break;
            switch (c) {
                case 'a' -> array[++nowDepth] = 1;
                case 'b' -> {
                    if (nowDepth == -1) {
                        ans = false;
                    } else if (array[nowDepth] == 1) {
                        array[nowDepth] = 2;
                    } else {
                        ans = false;
                    }
                }
                case 'c' -> {
                    if (nowDepth == -1) {
                        ans = false;
                    } else if (array[nowDepth] != 2) {
                        ans = false;
                    } else {
                        nowDepth--;
                    }
                }
            }
        }
        return ans && nowDepth == -1;
    }
}
