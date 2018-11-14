class Solution {
public:
    int countDigitOne(int n) {
        if(n < 10)//遞迴終止
            return n > 0;
        init();
        int ten = 10;
        while(n >= ten && ten < 1000000000){//超出int
            ten *= 10;
        }
        if(ten > n)//邊界
            ten /= 10;
        
        int a = n / ten, b = n % ten;
        if(a == 1)
            return b+1 + m[ten-1] + countDigitOne(b);
        else
            return ten + a*m[ten-1] + countDigitOne(b);
    }
private:
    void init(){//m[10 * a + 9] = a + 1 + m[a] * 10
        m[9]        = 1;
        m[99]       = 20;
        m[999]      = 300;
        m[9999]     = 4000;
        m[99999]    = 50000;
        m[999999]   = 600000;
        m[9999999]  = 7000000;
        m[99999999] = 80000000;
        m[999999999]= 900000000;
    }
    map<int, int>  m;
};