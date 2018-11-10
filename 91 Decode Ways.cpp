class Solution {
public:
    int numDecodings(string s) {
        if(s.find("00") != string::npos || s.find("30") != string::npos || 
           s.find("40") != string::npos || s.find("50") != string::npos ||
           s.find("60") != string::npos || s.find("70") != string::npos || 
           s.find("80") != string::npos || s.find("90") != string::npos ||
           s[0] == '0')
            return 0;
        fib(45);

        int re = 1, cnt = 0;
        for(int i = 0;i < s.size();++i){
            ++cnt;
            if(s[i] > '2'){
                if(i && s[i-1] == '2' && s[i] > '6')
                    --cnt;
                re *= arr[cnt];
                cnt = 0;
            }
            else if(s[i] == '0'){
                cnt -= 2;
                re *= arr[cnt];
                cnt = 0;
            }
        }
        re *= arr[cnt];

        return re;
    }
private:
    void fib(int n){
        for(int i = arr.size();arr.size() <= n;++i){
            arr.push_back(arr[i-1] + arr[i-2]);
        }
    }
    vector<int> arr = {1,1,2,3};
};