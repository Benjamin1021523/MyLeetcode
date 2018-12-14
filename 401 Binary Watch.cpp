class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        int cnt, nowi;
        for(int i = 0;i < 60;++i){
            cnt = 0;
            nowi = i;
            while(nowi > 0){
                cnt += nowi % 2;
                nowi >>= 1;
            }
            minute[cnt].push_back(itoa(i));
        }
        for(int i = num;i >= 0 && num - i < 7;--i){
            if(i >= 4)
                continue;
            combine(i, num - i);
        }
        return re;
    }
private:
    string itoa(int n){
        string a(2, '0');
        a[0] += (n / 10);
        a[1] += (n % 10);
        return a;
    }
    void combine(int h, int m){
        for(auto i:hour[h]){
            for(auto j:minute[m]){
                re.push_back(i + ":" + j);
            }
        }
    }
    vector<string> re;
    vector<vector<string>> hour = {{"0"}, {"1","2","4","8"}, {"3","5", "6", "9", "10"}, {"7", "11"}};
    vector<vector<string>> minute = {{}, {}, {}, {}, {}, {}, {}};
};