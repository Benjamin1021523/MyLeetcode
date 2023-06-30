class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack();

        for (char c : s.toCharArray()) {
            switch (c) {
                case 'a':
                case 'b':
                    stack.add(c);
                    break;
                case 'c':
                    if (stack.size() < 2) {
                        return false;
                    }
                    char pre = stack.pop();
                    char pre2 = stack.pop();
                    if (pre != 'b' || pre2 != 'a') {
                        return false;
                    }
                    break;
                default:
                    break;
            }
        }
        return stack.isEmpty();
    }
}