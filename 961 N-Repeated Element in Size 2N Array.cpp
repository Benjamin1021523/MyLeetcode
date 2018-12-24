class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        map<int, bool> m;
        for(auto& i:A){
            if(m[i])
                return i;
            m[i] = true;
        }
        return 0;
    }
};