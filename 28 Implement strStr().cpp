//string教學題
class Solution {
public:
    int strStr(string haystack, string needle) {
        size_t target = haystack.find(needle);
        if(target != string::npos)
            return target;
        return -1;
    }
};