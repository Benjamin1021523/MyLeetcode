class Solution {
public:
    string simplifyPath(string path) {
        path = '/' + path + '/';
        while(path.find("/./") != string::npos)
            path.replace(path.find("/./"), 3, "/");
        while(path.find("//") != string::npos)
            path.replace(path.find("//"), 2, "/");
        
        string temp = "/";
        vector<string> data;
        for(int i = 1;i < path.size();++i){
            if(path[i] == '/'){
                if(temp == "/.."){
                    if(!data.empty())
                        data.pop_back();
                }
                else
                    data.push_back(temp);
                temp = "/";
            }
            else{
                temp += path[i];
            }
        }
        if(data.empty())
            return "/";
        string re = "";
        for(auto& i:data)
            re += i;

        return re;
    }
};