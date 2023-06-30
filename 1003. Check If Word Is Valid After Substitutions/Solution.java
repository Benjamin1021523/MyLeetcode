class Solution {
    public boolean isValid(String s) {
        int sLength = s.length();
        while (!s.isEmpty()) {
            s = s.replaceAll("abc", "");
            if (s.length() == sLength) {
                return false;
            } else {
                sLength = s.length();
            }
        }
        return true;
    }
}