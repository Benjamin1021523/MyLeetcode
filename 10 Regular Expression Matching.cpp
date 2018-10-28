class Solution {
public:
    bool isMatch(string s, string p) {
        regex e(p);
        return regex_match (s, e);
    }
};