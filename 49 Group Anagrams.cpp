class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> strs) {
        vector<string> before(strs);
        string comp;
        vector<vector<string>> r;
        vector<string> check;
        for(int i = 0;i < strs.size();++i){
            sort(strs[i].begin(), strs[i].end());
            //cout << before[i] << " " << strs[i] << endl;
            int j = 0;
            for(;j < r.size();++j){
                if(check[j] == strs[i]){
                    r[j].push_back(before[i]);
                    break;
                }
            }
            if(j == r.size()){
                check.push_back(strs[i]);
                r.push_back({before[i]});
            }    
        }
        return r;
    }
};