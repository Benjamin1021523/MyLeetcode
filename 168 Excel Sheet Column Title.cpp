class Solution {
public:
    string convertToTitle(int n) {
        --n;
        string table = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string re;
        while(n >= 0){
            re = table[n % 26] + re;
            n /= 26;
            --n;
        }
        return re;
    }
};