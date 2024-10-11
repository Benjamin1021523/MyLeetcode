package com.easy.valid_parentheses_20;

import java.util.*;

class Solution extends AbstractSolution {

    public boolean isValid(String s) {
        Stack<Character> cStack = new Stack<>();

        boolean ans = true;
        for (char c : s.toCharArray()) {
            if (!ans) {
                break;
            }
            switch (c) {
                case '(', '[', '{' -> cStack.add(c);
                case ')', ']', '}' -> ans &= checkClosingBracket(cStack, c);
            }
        }
        return ans && cStack.isEmpty();
    }

    private static final Map<Character, Character> map = new HashMap<>() {{
        put('(', ')');
        put('[', ']');
        put('{', '}');
    }};

    private boolean checkClosingBracket(Stack<Character> cStack, char right) {
        if (cStack.isEmpty()) {
            return false;
        } else {
            Character top = cStack.pop();
            if (!map.get(top).equals(right)) {
                return false;
            }
        }
        return true;
    }
}
