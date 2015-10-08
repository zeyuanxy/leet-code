/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool compare(const Interval &a, const Interval &b) {
    return a.start < b.start;
} 

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        if(intervals.empty())
            return intervals;
        vector<Interval> ret;
        sort(intervals.begin(), intervals.end(), compare);
        Interval curr = intervals[0];
        for(int i = 1; i < intervals.size(); ++ i)
            if(curr.end < intervals[i].start) {
                ret.push_back(curr);
                curr = intervals[i];
            }
            else
                curr.end = max(curr.end, intervals[i].end);
        ret.push_back(curr);
        return ret;
    }
};