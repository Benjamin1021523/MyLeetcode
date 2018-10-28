class Solution {
public:
    int divide(int dividend, int divisor) {
        long long re = (long long)dividend / divisor;
        if(re > (1 << 31) - 1)
            return (1 << 31) - 1;
        if(re < -(1 << 31))
            return -(1 << 31);
        return re;
    }
};