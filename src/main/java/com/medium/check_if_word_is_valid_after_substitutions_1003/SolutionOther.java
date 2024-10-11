package com.medium.check_if_word_is_valid_after_substitutions_1003;

import java.util.*;

public class SolutionOther extends AbstractSolution {
    public boolean isValid(String s) {
        List<Integer> list = new ArrayList<>();

        boolean ans = true;
        for (char c : s.toCharArray()) {
            if (!ans) break;
            ans &= func(list, c);
        }
        return ans && list.isEmpty();
    }

    private static final Map<Character, Integer> map = new HashMap<>() {{
        int i = 0;
        for (char c1 : "abc".toCharArray()) {
            put(c1, i++);
        }
    }};

    private boolean func(List<Integer> list, char c) {
        if (map.get(c) == 0) {
            list.add(0);
        } else {
            if (list.isEmpty() || !Objects.equals(list.get(list.size() - 1), map.get(c) - 1)) {
                return false;
            } else if (map.get(c) == 2) {
                list.remove(list.size() - 1);
            } else {
                list.set(list.size() - 1, map.get(c));
            }
        }

        return true;
    }
}
