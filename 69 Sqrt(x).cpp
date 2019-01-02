class Solution {
public:
    int mySqrt(int x) {
        long long i = 1;
        while(i*i < (long long)x){
            i <<= 1;
        }
        if(i*i == (long long)x)    return i;
        i >>= 1;
        int y = i >> 1;
        while(y){
            if(i*i > (long long)x){
                i -= y;
            }
            else if(i*i < (long long)x){
                i += y;
            }
            else{
                return i;
            }
            y >>= 1;
        }
        while(i*i > (long long)x)  --i;
        return i;
    }
};