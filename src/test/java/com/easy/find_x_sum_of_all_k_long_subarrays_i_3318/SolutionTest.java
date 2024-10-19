package com.easy.find_x_sum_of_all_k_long_subarrays_i_3318;

import org.junit.jupiter.api.Test;

import java.util.Arrays;

class SolutionTest {

    final AbstractSolution solution = new Solution();

    @Test
    void testSolution() {
        int[] ans = solution.findXSum(new int[]{1,1,2,2,3,4,2,3}, 6, 2);
        int[] expected = new int[]{6,10,12};

        System.out.println(Arrays.toString(ans));
        System.out.println(Arrays.toString(expected));
    }
}