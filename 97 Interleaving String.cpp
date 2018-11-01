class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        bool re = 0;
        if(s1.size() + s2.size() != s3.size())
            return 0;
        if(s1.empty())
            return s2 == s3;
        if(s2.empty())
            return s1 == s3;

        if(!re && s1[0] == s3[0] && s1[s1.size()-1] == s3[s3.size()-1]){
            re |= isInterleave(s1.substr(1, s1.size()-2), s2, s3.substr(1, s3.size()-2));
        }//1前後
        if(!re && s2[0] == s3[0] && s2[s2.size()-1] == s3[s3.size()-1]){
            re |= isInterleave(s1, s2.substr(1, s2.size()-2), s3.substr(1, s3.size()-2));
        }//2前後
        if(!re && s1[0] == s3[0] && s2[s2.size()-1] == s3[s3.size()-1]){
            re |= isInterleave(s1.substr(1, s1.size()), s2.substr(0, s2.size()-1), s3.substr(1, s3.size()-2));
        }//1前2後
        if(!re && s2[0] == s3[0] && s1[s1.size()-1] == s3[s3.size()-1]){
            re |= isInterleave(s2.substr(1, s2.size()), s1.substr(0, s1.size()-1), s3.substr(1, s3.size()-2));
        }//2前1後
        return re;
    }
};