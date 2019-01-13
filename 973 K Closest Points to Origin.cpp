class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        map<int, vector<vector<int>>> m;
        for(auto& i:points)
            m[i[0]*i[0] + i[1]*i[1]].push_back(i);
        vector<vector<int>> re;
        auto it = m.begin();
        while(re.size() < K){
            re.insert(re.end(), (*it).second.begin(), (*it).second.end());
            ++it;
        }
        re.resize(K);
        return re;
    }
};