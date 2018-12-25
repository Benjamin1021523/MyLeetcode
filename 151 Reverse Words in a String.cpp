class Solution {
public:
    void reverseWords(string &s) {
        stringstream ss(s);
        s = "";
        string temp;
        while(ss >> temp){
            s = temp + " " + s;
        }
        if(s.size())
            s.erase(s.size()-1);
    }
};