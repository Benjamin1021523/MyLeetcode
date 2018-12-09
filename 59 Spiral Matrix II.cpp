class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        re.assign(1, {n*n});
        int w = n*n;
        for(int i = 1;i < n;++i){
            for(auto& j:re)
                j.push_back(--w);
            re.push_back({});
            while(re[re.size()-1].size() != i+1){
                re[re.size()-1].insert(re[re.size()-1].begin(), --w);
            }
        }
        for(int i = 2;i < n;++i)
            rotate(i);

        for(int i = 0;i < re.size()/2;++i){
            swap(re[i], re[re.size()-i-1]);
        }
        return re;
    }
private:
    void rotate(int leng){
        int center = leng-1;
        for(int i = 0;i < leng / 2;++i){//point reflection by center
            for(int j = 0;j < leng;++j){
                swap(re[i][j], re[center-i][center-j]);
            }
        }
        if(leng % 2){//reverse center row
            for(int i = 0;i < leng / 2;++i){
                swap(re[leng / 2][i], re[leng / 2][leng-1-i]);
            }
        }
    }
    vector<vector<int>> re;
};