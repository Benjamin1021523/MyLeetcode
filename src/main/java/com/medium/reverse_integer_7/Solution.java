package com.medium.reverse_integer_7;

public class Solution extends AbstractSolution {
    public int reverse(int x) {
        try {
            String s = String.valueOf(x);
            if (s.length() == 1) {
                return x;
            }

            StringBuilder stringBuilder = new StringBuilder();
            int lastIndex = 0;
            if (s.charAt(0) == '-') {
                stringBuilder.append(s.charAt(0));
                lastIndex = 1;
            }
            boolean leadingZero = true;
            for (int index = s.length() - 1; index >= lastIndex; index--) {
                char c = s.charAt(index);
                if (!leadingZero || c != '0') {
                    leadingZero = false;
                    stringBuilder.append(c);
                }
            }
            return Integer.parseInt(stringBuilder.toString());
        } catch (NumberFormatException e) {
            return 0;
        }
    }
}
