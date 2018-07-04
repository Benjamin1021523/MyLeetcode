class Solution {
public:
    bool isPowerOfTwo(int n) {
        while(n){
            if(n & 1){
                if(n >> 1)
                    return false;
                else
                    return true;
            }
            n >>= 1;
        }
        return false;
        /*
        bitset<32> b(n);//用時差不多
        if(!b[31]){
            if(b.count() == 1)
                return true;
        	else
                return false;
        }
        else
            return false;*/
    }
};