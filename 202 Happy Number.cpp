class Solution {
public:
    bool isHappy(int n) {
        bool arr[10] = {0, 1, 0, 0, 0, 0, 0, 1, 0, 0};
        int temp;
        while(n > 9){
            temp = 0;
            while(n){
                temp += (n % 10) * (n % 10);
                n /= 10;
            }
            n = temp;
        }
        return arr[n];
    }
};