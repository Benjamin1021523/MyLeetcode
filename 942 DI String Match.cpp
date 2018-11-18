class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> re(S.size()+1, 0);
        for(int i = 1;i < re.size();++i)
            re[i] = i;
        int last = re.size()-1;
        for(int i = 0;i < S.size();++i){
            if(S[i] == 'D'){
                int temp = re[last];
                re.erase(re.begin() + last);
                re.insert(re.begin() + i, temp);
            }
        }
        return re;
    }
};