class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() < 2)
            return s.size();
        //vector<bool> note(130, 0);//bitset比vector略快
        bitset<130> note;
        
        int cnt = 0;                   //這條件影響不大
        for(int i = 0;i < s.size() && s.size() - i > cnt;++i){
            //note.assign(130, 0);
            note.reset();
            int j;
            for(j = i;j < s.size() && !note[s[j]];++j){
                note[s[j]] = 1;
            }
            if(j - i > cnt)
                cnt = j - i;
        }
        return cnt;
    }
};