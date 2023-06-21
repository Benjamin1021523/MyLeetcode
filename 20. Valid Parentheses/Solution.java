class Solution {
    public boolean isValid(String s) {
        Stack<Character> cStack = new Stack<>();

        boolean ans = true;
        for (char c : s.toCharArray()) {
            if (!ans) {
                break;
            }
            switch (c) {
                case '(':
                case '[':
                case '{':
                    cStack.add(c);
                    break;
                case ')':
                    if (cStack.isEmpty()) {
                        ans = false;
                    } else if (!cStack.pop().equals('(')) {
                        ans = false;
                    }
                    break;
                case ']':
                    if (cStack.isEmpty()) {
                        ans = false;
                    } else if (!cStack.pop().equals('[')) {
                        ans = false;
                    }
                    break;
                case '}':
                    if (cStack.isEmpty()) {
                        ans = false;
                    } else if (!cStack.pop().equals('{')) {
                        ans = false;
                    }
                    break;
                default:
                    break;
            }
        }
        return ans && cStack.isEmpty();
    }
}