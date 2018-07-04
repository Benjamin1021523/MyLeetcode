class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> a(0);
        int now = 31;
        while(n){
            a[now--] = n & 1;
            n >>= 1;
        }
        return a.to_ulong();//最快等級的方法！

        /*uint32_t out = 0;
        int now = 31;
        while(n){
            out |= (n & 1) << now--;
            n >>= 1;
        }
        return out;*/
    }
};