class Solution {
public:
    int romanToInt(string s) {
        vector<string> str = {"MMM", "MM", "M", "CM", "DCCC", "DCC", "DC", "D", "CD", "CCC", "CC", "C", "XC", "LXXX", "LXX","LX", "L", "XL", "XXX", "XX", "X", "IX", "VIII", "VII", "VI", "V", "IV", "III", "II", "I"};
        vector<int> num = {3000, 2000, 1000, 900, 800, 700, 600, 500, 400, 300, 200, 100, 90, 80, 70, 60, 50, 40, 30, 20, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        int re = 0;
        for(int i = 0;i < str.size() && s.size();++i){
            if(str[i] == s.substr(0, str[i].size())){
                re += num[i];
                s.erase(0, str[i].size());
                if(i < 3)
                    i = 2;
                else if(i < 12)
                    i = 11;
                else if(i < 21)
                    i = 20;
                else
                    break;
            }
        }
        return re;
    }
};