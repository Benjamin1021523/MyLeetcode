class Solution {
public:
    double myPow(double x, int n) {
        if(x < 0 && !(n % 2))//-1.0 -2147483648
            x = -x;
        if(n == -2147483648){//x -2147483648
            x = 1 / x;
            n = 2147483647;
        }
        if(n < 0){
            x = 1 / x;
            n = -n;
        }
        int i = 0;
        double out = 1;
        while((1 << i) <= n && i <= 31){
            if((1 << i) & n){
                out *= x;
            }
            x *= x;
            ++i;
            //cout << out << endl;
        }
        return out;
    }
};