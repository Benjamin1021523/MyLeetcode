package com.easy.unique_email_addresses_929;

import com.common.AbstractSolutionTest;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.Map;

class SolutionTest extends AbstractSolutionTest<String[], Integer> {

    SolutionTest() {
        checkPoints = Map.ofEntries(
                Map.entry(new String[]{"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"}, 2),
                Map.entry(new String[]{"a@leetcode.com","b@leetcode.com","c@leetcode.com"},3)
        );
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

        for (Map.Entry<String[], Integer> entry : checkPoints.entrySet()) {
            String[] input = entry.getKey();
            Integer expected = entry.getValue();

            System.out.println("input: " + Arrays.toString(input));

            Assertions.assertEquals(expected, solution.numUniqueEmails(input));
        }
        System.out.println("通過測試");
    }
}