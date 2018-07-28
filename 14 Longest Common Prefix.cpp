class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
            return "";
        
        string data = strs[0];
        for(int i = 1;i < strs.size() && data.size();++i){
            if(data.size() > strs[i].size())
                data.resize(strs[i].size());
            for(int j = 0;j < data.size() && j < strs[i].size();++j){
                if(data[j] != strs[i][j]){
                    data[j] = 0;
                    break;
                }
            }
            data = data.substr(0, data.find(char(0)));
        }
        return data;
    }
};