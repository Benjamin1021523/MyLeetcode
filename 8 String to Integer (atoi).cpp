//重點是輸入很噁心
//真的非常噁心
class Solution {
public:
    int myAtoi(string str) {
        //這是個慢得離譜的做法
        regex e("^ *([+-]?)0*([0-9]+)");
        smatch m;
        if(!regex_search (str, m, e))
            return 0;

        bool sign = (m[1].str() == "-");//sign bit
        string after = m[2].str();      //unsigned number
        
        if(sign && after.size() > 10)
            return -2147483648;
        else if(after.size() > 10)
            return 2147483647;
        //有時似乎會出現size_t錯誤的測資
        
        size_t value = 0, int_max = 2147483647, int_min = 2147483648;
        for(int i = 0;i < after.size();++i){
            value *= 10;
            value += after[i] - '0';
        }//手動計算value

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
};