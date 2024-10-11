package com.easy.contains_duplicate_217;

import com.common.AbstractSolutionTest;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.Map;

class SolutionTest extends AbstractSolutionTest<Integer[], Boolean> {

    SolutionTest() {
        checkPoints = Map.ofEntries(
                Map.entry(new Integer[]{1, 2, 3, 1}, true), Map.entry(new Integer[]{1, 2, 3, 4}, false), Map.entry(new Integer[]{1,1,1,3,3,4,3,2,4,2}, true));
    }

    private final AbstractSolution solution = new Solution();

    @Test
    void testSolution() {
        containsDuplicate(solution);
    }

    void containsDuplicate(AbstractSolution solution) {

        for (Map.Entry<Integer[], Boolean> entry : checkPoints.entrySet()) {
            int[] input = toIntArray(entry.getKey());
            Boolean expected = entry.getValue();

            System.out.println("input: " + Arrays.toString(input));

            Assertions.assertEquals(expected, solution.containsDuplicate(input));
        }
        System.out.println("通過測試");
    }
}