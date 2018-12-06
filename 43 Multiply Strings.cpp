class Solution {
public:
    string multiply(string num1, string num2) {
        string re(230, '0');
        int carry = 0, i, j, n;
        for(i = 1;i <= num1.size();++i){
            for(j = 1;j <= num2.size();++j){
                n = (re[re.size()-i-j+1] - '0') + 
                    (num1[num1.size()-i] - '0') * (num2[num2.size()-j] - '0') + carry;
                re[re.size()-i-j+1] = '0' + n % 10;
                carry = n / 10;
            }
            re[re.size()-i-j+1] = '0' + carry;
            carry = 0;
        }
        i = 0;
        while(re[i++] == '0' && i < re.size()){}
        return re.substr(i-1, re.size());
    }
};