package com.medium.check_if_word_is_valid_after_substitutions_1003;

import com.common.AbstractSolutionTest;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.Map;

class SolutionTest extends AbstractSolutionTest<String, Boolean> {
    SolutionTest() {
        checkPoints = Map.ofEntries(
                Map.entry("aabcbc", true), Map.entry("abcabcababcc", true), Map.entry("abccba", false));
    }

    private final AbstractSolution solution = new Solution();
    private final AbstractSolution solutionOther = new SolutionOther();
    private final AbstractSolution solutionOther2 = new SolutionOther2();
    private final AbstractSolution solutionOther3 = new SolutionOther3();

    @Test
    void testSolution() {
        isValid(solution);
    }

    @Test
    void testSolutionOther() {
        isValid(solutionOther);
    }

    @Test
    void testSolutionOther2() {
        isValid(solutionOther2);
    }

    @Test
    void testSolutionOther3() {
        isValid(solutionOther3);
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