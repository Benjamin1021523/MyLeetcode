class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> data;
        for(int i = 0;i < words.size();++i){
            string temp = "";
            for(int j = 0;j < words[i].size();++j){
                temp += arr_s[words[i][j] - 'a'];
            }
            if(data.find(temp) == data.end()){
                data.insert(temp);
            }
        }
        return data.size();
    }
private:
    string arr_s[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
};