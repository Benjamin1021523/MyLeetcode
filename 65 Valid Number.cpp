class Solution {
public:
    bool isNumber(string s) {
        //超級慢
        regex e("^ *[+-]?(([0-9]+\\.?[0-9]*)|(\\.[0-9]+))(e[+-]?[0-9]+)? *$");
        return std::regex_match (s, e);
    }
};