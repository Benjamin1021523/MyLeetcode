package com.medium.reverse_integer_7;

import com.common.AbstractSolutionTest;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.Map;

class SolutionTest extends AbstractSolutionTest<Integer, Integer> {

    SolutionTest() {
        checkPoints = Map.ofEntries(
                Map.entry(123, 321), Map.entry(-120, -21), Map.entry(0, 0), Map.entry(-1, -1), Map.entry(1534236469, 0),
                Map.entry(-2147483648, 0)
        );
    }

    final AbstractSolution solution = new Solution();
    final AbstractSolution solution2 = new Solution2();

    @Test
    void testSolution() {
        reverse(solution);
    }

    @Test
    void testSolution2() {
        reverse(solution2);
    }

    void reverse(AbstractSolution solution) {

        for (Map.Entry<Integer, Integer> entry : checkPoints.entrySet()) {
            Integer input = entry.getKey();
            Integer expected = entry.getValue();

            System.out.println("input: " + input);

            Assertions.assertEquals(expected, solution.reverse(input));
        }
        System.out.println("通過測試");
    }
}