class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        vector<int> ans(4, -1);
        permutations({}, A);
        for(int i = 0;i < per.size();++i){
            if(per[i][0]*10 + per[i][1] >= 24 || per[i][2]*10 + per[i][3] > 59){
                per.erase(per.begin()+i);
                --i;
                continue;
            }
            if(per[i][0]*10 + per[i][1] > ans[0]*10 + ans[1]){
                ans.assign(per[i].begin(), per[i].end());
            }
            if(per[i][0]*10 + per[i][1] == ans[0]*10 + ans[1]){
                if(per[i][2]*10 + per[i][3] > ans[2]*10 + ans[3])
                    ans[2] = per[i][2], ans[3] = per[i][3];
            }
        }
        if(ans[0] == -1)
            return "";
        else
            return string("") + char('0'+ans[0]) + char('0'+ans[1]) + ":" + char('0'+ans[2]) + char('0'+ans[3]);
    }
private:
    void permutations(vector<int> pre, vector<int> A){
        if(A.empty())
            per.push_back(pre);
        for(int i = 0;i < A.size();++i){
            vector<int> pre_t(pre.begin(), pre.end());
            vector<int> A_t(A.begin(), A.end());

            pre_t.push_back(A[i]);
            A_t.erase(A_t.begin()+i);
            permutations(pre_t, A_t);
        }
    }
    vector<vector<int>> per;
};