class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> word;
        vector<string> word_k;
        vector<string> digit;
        for(auto& i:logs){
            if(i[i.find(" ")+1] >= '0' && i[i.find(" ")+1] <= '9'){
                digit.push_back(i);
            }
            else{
                word.push_back(i);
                word_k.push_back(i.substr(i.find(" ")+1, i.find(" ", i.find(" ")+1)-(i.find(" ")+1)));
            }
        }
        for(int i = 0;i < word_k.size()-1;++i){
            for(int j = i+1;j < word_k.size();++j){
                if(word_k[i] > word_k[j]){
                    swap(word_k[i], word_k[j]);
                    swap(word[i], word[j]);
                }
            }
        }
        vector<string> re(word);
        re.insert(re.end(), digit.begin(), digit.end());
        return re;
    }
};