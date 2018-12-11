class Solution {
public:
    int lastRemaining(int n) {
        if(n == 1)
            return 1;
        return n - (n % 2) - lastRemaining(n / 2) * 2 + 2;
    }
};
/**
不論n是奇數或偶數，留下來的都是所有的偶數項
以n = 8為例，下一層n = 4回傳是1~4，經過處理再往上傳要變成8,6,4,2
最後以程式中的規則

一開始解用vector erase，後來用兩個stack互倒，都超時了
*/