class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        v.push_back(INT_MIN);
    }
    
    void push(int x) {
        s.push(x);
        int i = 0;
        for(;i < v.size() && v[i] < x;++i){}
        v.insert(v.begin()+i, x);
    }
    
    void pop() {
        int t = s.top();
        s.pop();
        int i = 0;
        for(;v[i] != t;++i){}
        v.erase(v.begin()+i);
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return v[1];
    }
    vector<int> v;
    stack<int> s;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */