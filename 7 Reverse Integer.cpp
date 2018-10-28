class Solution {
public:
    int reverse(int x) {
        if(x == 0)
            return 0;
        bool sign = 1;
        if(x < 0){
            sign = 0;
            x *= -1;
        }
        while(x % 10 == 0){
            x /= 10;
        }
        long long out = 0;
        while(x != 0){
            out *= 10;
            out += x % 10;
            x /= 10;
        }
        if(out > ((long long)1<<31)-1 || out < -1 * ((long long)1<<31))
            return 0;
        if(!sign)
            return -1 * out;
        return out;
    }
};