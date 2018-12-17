class Solution {
public:
    vector<string> fizzBuzz(int n) {
        stringstream ss;
        for(int i = 1;i <= n;++i)
            ss << i << " ";
        vector<string> re(n, "");
        string temp;
        for(int i = 1;i <= n;++i){
            ss >> temp;
            if(i % 15 == 0)
                re[i-1] = "FizzBuzz";
            else if(i % 3 == 0)
                re[i-1] = "Fizz";
            else if(i % 5 == 0)
                re[i-1] = "Buzz";
            else
                re[i-1] = temp;
        }
        return re;
    }
};