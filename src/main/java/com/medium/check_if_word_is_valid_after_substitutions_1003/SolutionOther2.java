package com.medium.check_if_word_is_valid_after_substitutions_1003;

import java.util.Stack;

/**
 * 改自 https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/solutions/3067699/java-c-100-solution-using-stack-check-if-word-is-valid-after-substitutions/
 */
public class SolutionOther2 extends AbstractSolution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack();

        for (char c : s.toCharArray()) {
            switch (c) {
                case 'a':
                case 'b':
                    stack.add(c);
                    break;
                case 'c':
                    if (stack.size() < 2) {
                        return false;
                    }
                    char pre = stack.pop();
                    char pre2 = stack.pop();
                    if (pre != 'b' || pre2 != 'a') {
                        return false;
                    }
                    break;
                default:
                    break;
            }
        }
        return stack.isEmpty();
    }
}
