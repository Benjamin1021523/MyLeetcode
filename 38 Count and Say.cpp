class Solution {
public:
    string countAndSay(int n) {
        if(!f)
            init();
        return v[n-1].substr(0, v[n-1].size()-1);
    }
private:
    void init(){
        f = 1;
        v.assign(1, "1.");
        for(int i = 0;i < 30;i++){
            string temp = "";

            char a = v[i][0];
            int cnt = 1;
            for(int j = 1;j < v[i].size();j++){
                if(v[i][j] == a){
                    cnt++;
                }
                else{
                    temp += '0' + cnt;
                    temp += a;
                    a = v[i][j];
                    cnt = 1;
                }
            }
            //cout << temp << endl;
            v.push_back(temp + ".");
        }
    }
    vector<string> v;
    bool f;
};