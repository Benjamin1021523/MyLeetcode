class Solution {
public:
    int trailingZeroes(int n) {
        int re = 0;
        while(n > 4){
            n /= 5;
            re += n;
        }
        return re;
    }
};