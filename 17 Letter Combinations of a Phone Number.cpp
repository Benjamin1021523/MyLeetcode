class Solution {
public:
    vector<string> letterCombinations(string digits) {
        out.resize(0);
        if(!digits.size())
            return out;
        in = digits;
        getstr();
        return out;
    }
private:
    void getstr(){
        get("", 0);
    }
    void get(string s, int index){
        if(index == in.size()){
            out.push_back(s);
        }
        else{
            for(int i = 0;i < table[in[index] - '0'].size();++i){
                get(s + table[in[index] - '0'][i], index + 1);
            }
        }
    }
    vector<string> out;
    string in;
    string table[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
};