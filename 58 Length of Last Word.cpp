class Solution {
public:
    int lengthOfLastWord(string s) {
        auto t = string::npos;
        while((t = s.find_last_of(" ")) != string::npos){
            if(t == s.size() - 1)
                s.resize(t);
            else
                return s.size() - t - 1;
        }
        return s.size();
    }
    /*int lengthOfLastWord(string s) {//同4ms
        int cnt = 0;
        for(int i = s.size()-1;i >= 0;--i){
            s[i] |= 32;//一律轉小寫
            if(!(s[i] >= 'a' && s[i] <= 'z'))
                if(!cnt)
                    continue;
                else
                    break;
            else
                ++cnt;
        }
        return cnt;
    }*/
};