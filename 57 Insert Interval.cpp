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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        if(intervals.empty() || intervals[intervals.size()-1].end < newInterval.start){
            intervals.push_back(newInterval);
            return intervals;
        }
        if(newInterval.end < intervals[0].start){
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        }
        int i = 0;
        for(;i < intervals.size();++i){
            //這段待精簡
            if((intervals[i].start <= newInterval.end && newInterval.end <= intervals[i].end) || 
               (newInterval.start <= intervals[i].start && intervals[i].start <= newInterval.end) || 
               (intervals[i].start <= newInterval.start && newInterval.start <= intervals[i].end) || 
               (newInterval.start <= intervals[i].end && intervals[i].end <= newInterval.end)){
                intervals[i].start = min(intervals[i].start, newInterval.start);
                intervals[i].end = max(intervals[i].end, newInterval.end);
                break;
            }
            if(i > 0 && intervals[i-1].end < newInterval.start && 
                        intervals[i].start > newInterval.end){
                intervals.insert(intervals.begin()+i, newInterval);
                return intervals;
            }
        }
        while(i < intervals.size()-1 && intervals[i].end >= intervals[i+1].start){
            intervals[i].end = max(intervals[i].end, intervals[i+1].end);
            intervals.erase(intervals.begin()+i+1);
        }
        
        return intervals;
    }
};
//效率非常的低，以後修正