class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        map<int, set<int>> m;
        int ma = 0;
        for(auto& i:people){
            m[i.second].insert(i.first);
            ma = max(ma, i.second);
        }
        vector<pair<int, int>> re;
        for(auto& i:m[0]){
            re.push_back(make_pair(i, 0));
        }//由小到大放Height0的值必然正確
        int cnt, k;
        for(int i = 1;i <= ma;++i){
            for(auto& j:m[i]){
                cnt = i;//記錄前面要有i個比j大的值
                for(k = 0;k < re.size() && cnt;++k){
                    if(re[k].first >= j){
                        --cnt;
                    }//湊足i個的數量
                }
                for(;k < re.size() && re[k].first < j;++k){}
                //避免影響k後面現有的項目
                re.insert(re.begin() + k, make_pair(j, i));
            }
        }
        return re;
    }
};