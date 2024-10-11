package com.easy.contains_duplicate_217;

import java.util.HashSet;
import java.util.Set;

public class Solution extends AbstractSolution {
    public boolean containsDuplicate(int[] nums) {
        Set<Integer> set = new HashSet<>();

        for (int i : nums) {
            if (!set.add(i)) {
                return true;
            }
        }
        return false;
    }
}
