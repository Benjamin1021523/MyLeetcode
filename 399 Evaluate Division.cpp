class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        int ori = equations.size();//記錄一開始的資料長度
        map<string, double> m;//記錄各字串代表的數值
        m[equations[0].first] = values[0];
        m[equations[0].second] = 1;
        //先把[0]寫入，在迴圈中找其他和[0]有關的項目
        vector<set<string>> s(1, set<string>());//紀錄哪些字串有關，哪些無關
        s[0].insert(equations[0].first);
        s[0].insert(equations[0].second);
        //同理，[0]屬於第0組
        int write_s = 0, wrong = 0;
        //  目前到第?組  有多少項不屬於第0組
        for(int i = 1;i < equations.size();++i){
            if(m[equations[i].first] != 0.0){//關聯點在first
                s[write_s].insert(equations[i].second);
                m[equations[i].second] = m[equations[i].first] / values[i];
                //記錄second的值，以及所屬的組數
            }
            else if(m[equations[i].second] != 0.0){//關聯點在second
                s[write_s].insert(equations[i].first);
                m[equations[i].first] = m[equations[i].second] * values[i];
                //記錄first的值，以及所屬的組數
            }
            else{
                if(i < ori)//超過一開始的長度會重複算
                    ++wrong;
                //假設有四項無法解決進入循環，每循環解決一項的話大約會增加4+3+2+1的長度，不算那麼精準了
                if(wrong * wrong + ori < equations.size()){
                    s.push_back(set<string>());//開一個新的分組
                    ++write_s;//不會再新增到上個分組了
                    s[write_s].insert(equations[i].first);
                    s[write_s].insert(equations[i].second);
                    m[equations[i].first] = values[i];
                    m[equations[i].second] = 1;
                    --wrong;
                }
                else{//丟到以後解決，湊夠多了之後用上面的if處理
                    equations.push_back(equations[i]);
                    values.push_back(values[i]);
                }
            }
        }
        vector<double> re;
        for(auto& i:queries){
            int x = 0, y = 0;
            for(;x < s.size() && s[x].find(i.first) == s[x].end();++x){}
            for(;y < s.size() && s[y].find(i.second) == s[y].end();++y){}
            //x和y表示first和second所屬的分組，之前都不符合(所以用這樣的條件)

            //x是不存在的||y是不存在的||x和y不同組
            if(x == s.size() || y == s.size() || x != y){
                re.push_back(-1);
            }
            else{
                re.push_back(m[i.first] / m[i.second]);
            }
        }
        return re;
    }
};
/**
這題根本難度詐欺(崩潰)
ori 記錄一下一開始的長度
*/