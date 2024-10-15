package com.medium.reverse_integer_7;

public class Solution2 extends AbstractSolution {
    public int reverse(int x) {
        boolean sign = x < 0;
        int output = 0;

        int temp = Math.abs(x);
        while (temp != 0) {
            int lastDigit = temp % 10;

            if ((Integer.MAX_VALUE - lastDigit) / 10 < output) {
                return 0;
            }

            output = output * 10 + lastDigit;
            temp /= 10;
        }
        if (sign) {
            output = -output;
        }
        return output;
    }
}
