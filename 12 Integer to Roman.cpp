class Solution {
public:
    string intToRoman(int num) {
        string arr[4][9] = {{"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
                            {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
                            {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
                            {"M", "MM", "MMM"}
                           };
        int i = 0;
        string out;
        while(num){
            if(num % 10 == 0){
                num /= 10, i++;
                continue;
            }
            out = arr[i++][num % 10 - 1] + out;
            num /= 10;
        }
        return out;
    }
};