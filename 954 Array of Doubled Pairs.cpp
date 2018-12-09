class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        map<int, int> m1, m2;
        for(auto& i:A){
            if(i >= 0)
                ++m1[i];
            else
                ++m2[-i];
        }
        for(auto& i:m1){
            if(i.second <= m1[i.first*2]){
                if(i.first == 0 && i.second % 2)
                    return false;
                m1[i.first*2] -= i.second;
            }
            else
                return false;
        }
        for(auto& i:m2){
            if(i.second <= m2[i.first*2]){
                m2[i.first*2] -= i.second;
            }
            else
                return false;
        }
        return true;
    }
};