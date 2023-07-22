// 改自討論區方法，找不到原討論串

class Solution {
    public boolean isValid(String s) {
        char[] cs = s.toCharArray();
        int i = 0;
        for (char c : cs) {
            if (c != 'a') {
                if (i == 0) {
                    return false;
                } else {
                    --i;
                    if (c != cs[i] + 1) {// 字元非a的情況一定要是b或c，前一個應為對應的a或b
                        return false;
                    }
                }
            }

            if (c != 'c') {
                cs[i] = c;
                ++i;
            }
        }
        return i == 0;
    }
}