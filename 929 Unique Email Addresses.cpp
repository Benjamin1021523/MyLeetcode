class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> m;
        for(auto& i:emails){
            string temp = i.substr(i.find("@") + 1, i.size());
            if(m.find(temp) == m.end()){
                m.insert(temp);
            }
        }
        return m.size();
    }
};