class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return 0;
        int x2 = x, store = 0;
        while(x2 != 0){
            store *= 10;
            store += x2 % 10;
            x2 /= 10;
        }
        return x == store;
    }
};