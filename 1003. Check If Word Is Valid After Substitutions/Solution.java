class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();

        boolean ans = true;
        for (char c : s.toCharArray()) {
            if (!ans) break;
            switch (c) {
                case 'a':
                    stack.add(c);
                    break;
                case 'b':
                    if (stack.isEmpty()) {
                        ans = false;
                    } else if (stack.pop().equals('a')) {
                        stack.add(c);
                    } else {
                        ans = false;
                    }
                    break;
                case 'c':
                    if (stack.isEmpty()) {
                        ans = false;
                    } else if (!stack.pop().equals('b')) {
                        ans = false;
                    }
                    break;
                default:
                    break;
            }
        }
        return ans && stack.isEmpty();
    }
}