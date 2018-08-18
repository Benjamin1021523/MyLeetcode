class Solution {
public:
    bool isValid(string s) {
        //看起來很醜也不快的方法
		/*stack<char> q;
        char now;
        for(auto& i : s){
            now = 0;
            switch(i){
                case '(':
                    q.push(1);
                    break;
                case '[':
                    q.push(2);
                    break;
                case '{':
                    q.push(3);
                    break;
                
                case ')':
                    if(q.empty() || q.top() != 1)
                        return 0;
                    q.pop();
                    break;
                case ']':
                    if(q.empty() || q.top() != 2)
                        return 0;
                    q.pop();
                    break;
                case '}':
                    if(q.empty() || q.top() != 3)
                        return 0;
                    q.pop();
                    break;
                default:
                    break;
            }
        }
        return q.empty();*/
		
		//比較好看但是超級慢的方法
        /*while(s.find("()") != string::npos || s.find("[]") != string::npos || 
            s.find("{}") != string::npos){
            while(s.find("()") != string::npos){
                s.replace(s.find("()"), 2, "");
            }
            while(s.find("[]") != string::npos){
                s.replace(s.find("[]"), 2, "");
            }
            while(s.find("{}") != string::npos){
                s.replace(s.find("{}"), 2, "");
            }
        }
        return s.empty();*/
		
		//用map簡化第一個方法
		stack<char> q;
        map<char, char> m;
        m[')'] = '(';
        m[']'] = '[';
        m['}'] = '{';
        for(auto& i : s){
            if(!m[i])
                q.push(i);
            else if(q.empty() || m[i] != q.top())
                return 0;
            else
                q.pop();
        }
        return q.empty();
    }
};