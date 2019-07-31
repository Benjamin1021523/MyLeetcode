class Solution {
    public boolean isHappy(int n) {
        int temp;
        while(n > 9){
            temp = 0;
            while(n > 0){
                temp += (n % 10) * (n % 10);
                n /= 10;
            }
            n = temp;
        }
        return n == 1 || n == 7;
    }
}
