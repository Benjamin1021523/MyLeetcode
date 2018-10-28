class Solution {
public:
    string toLowerCase(string str) {
        for(char& i:str){
            i |= 32;
        }
        return str;
    }
};