//小小的練習題
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int re = 0;
        while(n){
            re += n & 1;
            n >>= 1;
        }
        return re;
        /*		
        bitset<32> data(n); //STL雖然方便，但是這題手動略快
        return data.count();
		*/
    }
};