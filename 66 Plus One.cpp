//大數加法的極簡化版
class Solution {
public:
    vector<int> plusOne(vector<int> digits) {
        ++digits[digits.size()-1];
        int i = digits.size()-1;
        while(digits[i] == 10){
            digits[i--] = 0;
            if(i == -1){
                digits.insert(digits.begin(), 1);
                break;
            }
            ++digits[i];
        }
        return digits;
    }
};