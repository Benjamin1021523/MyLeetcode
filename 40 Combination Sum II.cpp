class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        for(int i = 0;i < candidates.size();++i){
            if(candidates[i] > target)
                break;
            if(i > 0 && candidates[i] == candidates[i-1])
                continue;
            f({candidates[i]}, candidates, i+1, target-candidates[i]);
        }
        return re;
    }
private:
    void f(vector<int> pre, vector<int>& candidates, int now, int target){
        if(target == 0){
            re.push_back(pre);
            return;
        }
        if(target < candidates[now])    return;
        pre.push_back(0);
        for(int i = now;i < candidates.size();++i){
            if(candidates[i] > target)
                break;
            if(i > now && candidates[i] == candidates[i-1])
                continue;
            pre[pre.size()-1] = candidates[i];
            f(pre, candidates, i+1, target-candidates[i]);
        }
    }
    vector<vector<int>> re;
};