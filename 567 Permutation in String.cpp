class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        auto s1s = s1.size(), s2s = s2.size();
        if(s1s > s2s)
            return false;

        for(auto& i:s1)
            ++origin[i];
        int i = 0;
        for(;i < s1s;++i){
            ++compare[s2[i]];
        }//i = s1s
        for(;i < s2s;++i){
            if(comp())
                return true;
            --compare[s2[i-s1s]];
            ++compare[s2[i]];
        }
        if(comp())
            return true;
        return false;
    }
private:
    bool comp(){
        for(auto i:origin){
            if(i.second != compare[i.first])
                return false;
        }
        return true;
    }
    map<char, int> origin;
    map<char, int> compare;
};