class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k >= num.size())
            return "0";
        for(int i = 0;i < k;++i){
            int x = 0;
            while(x < num.size()-1 && num[x] <= num[x+1])    ++x;
            num.erase(x, 1);
        }
        int i = 0;
        for(;i < num.size()-1 && num[i] == '0';++i){}
        return num.substr(i);
    }
};