class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        string totalB = "";
        int cnt = 0, st, j;
        string temp;
        auto place = string::npos;
        for(string i:B){
            st = 0;temp = "";
            for(auto& j:i){
                if((place = totalB.find(j, st)) != string::npos)
                    swap(totalB[st++], totalB[place]);
                else
                    temp += j;
            }
            totalB += temp;
        }
        vector<string> re;
        int thing = 0;
        for(auto i:A){
            st = 0;
            for(auto& j:totalB){
                if((place = i.find(j, st)) != string::npos){
                    swap(i[st++], i[place]);
                }
                else
                    break;
            }
            if(st == totalB.size())
                re.push_back(A[thing]);
            thing++;
        }
        return re;
    }
};