class Solution {
public:
    int longestSubstring(string s, int k) {
        map<char, int> m;
        string yes = "";
        for(auto& i:s){
            ++m[i];
            if(m[i] == k)
                yes += i;//紀錄哪些字元是符合的，組成字串yes
        }
        //如果整個s都沒有例外，回傳s.size()
        if(s.find_first_not_of(yes) == string::npos)
            return s.size();

        s.erase(0, s.find_first_of(yes));//把前面多餘的部分拿掉
        int re = 0, edge;
        while(s.find_first_of(yes) != string::npos){
            edge = s.find_first_not_of(yes);//s的0~edge-1都是yes的成員
            re = max(re, longestSubstring(s.substr(0, edge), k));
            s.erase(0, s.find_first_of(yes, edge));
            //s的開頭0~?是下一部分的yes成員
        }
        return re;
    }
};
/**
舉例來說，輸入("aabcaabb", 2)
yes = "ab"
分成("aab", 2)和("aabb", 2)兩組
    yes = "a"    yes = "ab"
    回傳2        回傳4
回傳max(2, 4) => 4
這樣分解的效率應該蠻高的，至少結果是0ms解答
*/