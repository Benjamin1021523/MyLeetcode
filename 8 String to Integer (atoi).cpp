class Solution {
public:
    int myAtoi(string str) {
        size_t value = 0, int_max = 2147483647, int_min = 2147483648;
        bool sign = 0;
        for(int i = 0;i < str.size();++i){//這迴圈只是處理前置空白和正負號而已
            if(str[i] == ' ' || str[i] == '\t')//空白省略
                continue;
            if(str[i] == '-'){
                sign = 1;//負的做個標記，從下個字元開始計數
                value = read_v(str, i+1);
                break;
            }
            else if(str[i] == '+'){//正的直接從下個開始計數
                value = read_v(str, i+1);
                break;
            }
            else{//不然都直接當數字試試
                value = read_v(str, i);
                break;
            }
        }
        if(sign){
            if(value > int_min)
                return -2147483648;
            return -1 * value;
        }
        else{
            if(value > int_max)
                return 2147483647;
            return value;
        }
    }
private:
    size_t read_v(string& str, int i){
        size_t value = 0;
        for(;i < str.size();++i){
            if(str[i] < '0' || str[i] > '9'){
                return value;//只要不是數字開頭都算錯
            }
            else{
                value *= 10;
                value += str[i] - '0';
            }
            if(value > 2147483648){//超過int範圍時
                return 2147483648;
            }
        }
        return value;
    }
};