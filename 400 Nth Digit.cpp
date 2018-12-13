class Solution {
public:
    int findNthDigit(int n) {
        long long int l = 1, i = 1;//可能超出邊界
        while(n > l * i * 9){//l放前面運算結果會是LL
            n -= 9 * l * i;//這裡就沒差了
            l *= 10;++i;
        }
        int start = l;
        start += n / i;
        n %= i;
        if(n == 0)
            return (start-1) % 10;
        int re;
        for(int i = 0;i < n && l;++i){
            re = start / l;
            start %= l;
            l /= 10;
        }
        return re;
    }
};