class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> re(A.size(), 0);
        int f = -1, e = A.size();
        for(auto& i:A){
            if(i & 1){
                re[--e] = i;
            }
            else{
                re[++f] = i;
            }
        }
        return re;
    }
};