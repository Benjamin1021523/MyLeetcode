class Solution {
public:
    int integerReplacement(int n, int cnt = 0) {
        if(n == 2147483647)
            return 32;
        if(n == 1)
            return cnt;
        if(n % 2 == 0)
            return integerReplacement(n >> 1, cnt + 1);
        else
            return min(integerReplacement(n + 1, cnt + 1), 
                       integerReplacement(n - 1, cnt + 1));
    }
};