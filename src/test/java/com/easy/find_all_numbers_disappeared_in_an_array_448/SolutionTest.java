package com.easy.find_all_numbers_disappeared_in_an_array_448;

import com.common.AbstractSolutionTest;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.List;
import java.util.Map;

class SolutionTest extends AbstractSolutionTest<Integer[], List<Integer>> {

    SolutionTest() {
        checkPoints = Map.ofEntries(
                Map.entry(new Integer[]{4,3,2,7,8,2,3,1}, List.of(5,6)), Map.entry(new Integer[]{1,1}, List.of(2)));
    }

    private final AbstractSolution solution = new Solution();

    @Test
    void testSolution() {
        findDisappearedNumbers(solution);
    }

    private final AbstractSolution solutionOther = new SolutionOther();

    @Test
    void testSolutionOther() {
        findDisappearedNumbers(solutionOther);
    }

    void findDisappearedNumbers(AbstractSolution solution) {
        for (Map.Entry<Integer[], List<Integer>> entry : checkPoints.entrySet()) {
            int[] input = toIntArray(entry.getKey());
            List<Integer> expected = entry.getValue();

            System.out.println("input: " + Arrays.toString(input));

            Assertions.assertEquals(expected, solution.findDisappearedNumbers(input));
        }
        System.out.println("通過測試");
    }
}