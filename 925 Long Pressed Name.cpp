class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int readName = 0;
        for(int i = 0;i < typed.size() && readName != name.size();++i){
            if(typed[i] == name[readName]){
                ++readName;
            }
        }
        return readName == name.size();
    }
};