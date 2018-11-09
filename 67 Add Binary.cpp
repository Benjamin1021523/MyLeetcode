class Solution {
public:
    #define v(a) a-'0'
    string addBinary(string a, string b) {
        if(a.size() < b.size())
            swap(a, b);
        b = string(a.size()-b.size(), '0') + b;
        bool carry = 0;char value;
        for(int i = 1;i <= a.size();++i){
            a[a.size()-i] += carry;
            value = v(a[a.size()-i]) + v(b[b.size()-i]);
            carry = value >= 2;
            a[a.size()-i] = (value & 1) + '0';
        }
        if(carry)
            return "1" + a;
        return a;
    }
};