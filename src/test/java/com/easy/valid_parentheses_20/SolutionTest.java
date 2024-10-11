package com.easy.valid_parentheses_20;

import com.common.AbstractSolutionTest;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.Map;

class SolutionTest extends AbstractSolutionTest<String, Boolean> {

    SolutionTest() {
        checkPoints = Map.ofEntries(
                Map.entry("()", true), Map.entry("()[]{}", true), Map.entry("(]", false), Map.entry("([])", true));
    }

    private final AbstractSolution solution = new Solution();
    private final AbstractSolution solutionOther = new SolutionOther();

    @Test
    void testSolution() {
        isValid(solution);
    }

    @Test
    void testSolutionOther() {
        isValid(solutionOther);
    }

    void isValid(AbstractSolution solution) {

        for (Map.Entry<String, Boolean> entry : checkPoints.entrySet()) {
            String input = entry.getKey();
            Boolean expected = entry.getValue();

            System.out.println("input: " + input);

            Assertions.assertEquals(expected, solution.isValid(input));
        }
        System.out.println("通過測試");
    }
}