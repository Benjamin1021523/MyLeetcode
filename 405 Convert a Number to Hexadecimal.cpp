class Solution {
public:
    string toHex(int num) {
        char arr[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        string re;
        if(num >= 0){
            if(num == 0)
                return "0";
            while(num > 0){
                re = arr[num % 16] + re;
                num >>= 4;
            }
            return re;
        }
        else{
            ++num;
            num *= -1;
            while(num > 0){
                re = arr[15 - num % 16] + re;
                num >>= 4;
            }
            return string(8 - re.size(), 'f') + re;
        }
    }
};