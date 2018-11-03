class Solution {
public:
    string reverseOnlyLetters(string S) {
        string re;
        for(int i = S.size()-1;i >= 0;--i){
            if((S[i] | 32) >= 'a' && (S[i] | 32) <= 'z'){
                re += S[i];
            }
        }
        for(int i = 0;i < S.size();++i){
            if(!((S[i] | 32) >= 'a' && (S[i] | 32) <= 'z')){
                re.insert(re.begin()+i, S[i]);
            }
        }
        return re;
    }
};//這方法比字串內前後交換來得快