package com.easy.find_all_numbers_disappeared_in_an_array_448;

import java.util.ArrayList;
import java.util.List;

public class Solution extends AbstractSolution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        boolean[] existNumber = new boolean[nums.length];

        for (int num : nums) {
            existNumber[num - 1] = true;
        }

        List<Integer> ans = new ArrayList<>();
        for (int index = 0;index < existNumber.length; index++) {
            if (!existNumber[index]) {
                ans.add(index + 1);
            }
        }

        return ans;
    }
}
