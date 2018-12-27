/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.empty())
            return intervals;
        f(intervals);
        return intervals;
    }
private:
    void f(vector<Interval>& v){
        map<int, int> m;
        for(auto i:v){
            m[i.start] = max(m[i.start], i.end);
        }
        int write = 0;
        Interval t((*m.begin()).first, (*m.begin()).second);
        for(auto i:m){
            if(t.end >= i.first){
                t.end = max(t.end, i.second);
            }
            else{
                v[write++] = t;
                t = Interval(i.first, i.second);
            }
        }
        v[write++] = t;
        v.resize(write);
    }
};