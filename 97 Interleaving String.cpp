class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size())
            return false;
        if(s1.empty() || s2.empty())
            return s1+s2==s3;
        bool arr[s1.size()+1][s2.size()+1];
        memset(arr, false, sizeof(arr));

        arr[0][0] = true;
        for(int i = 1;arr[i-1][0] && i < s1.size()+1;++i){
            arr[i][0] = (s1[i-1] == s3[i-1]);
        }
        for(int i = 1;arr[0][i-1] && i < s2.size()+1;++i){
            arr[0][i] = (s2[i-1] == s3[i-1]);
        }
        int i = 1, j = 1;
        for(;i < s1.size()+1;++i){
            for(j = 1;j < s2.size()+1;++j){
                arr[i][j] = (arr[i-1][j] && s3[i+j-1] == s1[i-1]) || 
                            (arr[i][j-1] && s3[i+j-1] == s2[j-1]);
            }
        }
        return arr[i-1][j-1];
    }
};