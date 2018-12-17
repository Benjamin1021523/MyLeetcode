class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1.size() < num2.size())
            num1.insert(num1.begin(), num2.size() - num1.size(), '0');
        else
            num2.insert(num2.begin(), num1.size() - num2.size(), '0');
        //num1.size() == num2.size()

        bool carry = false;
        for(int i = 1;i <= num2.size();++i){
            num1[num2.size()-i] += num2[num2.size()-i] - '0' + carry;
            if(carry = (num1[num2.size()-i] > '9')){
                num1[num2.size()-i] -= 10;
            }
        }
        if(carry)
            num1.insert(num1.begin(), '1');
        return num1;
    }
};