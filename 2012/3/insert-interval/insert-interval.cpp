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
    bool overlap(Interval &a, Interval &b) {
        if((a.end >= b.start && a.end <= b.end) || (b.end >= a.start && b.end <= a.end)) {
            b.start = min(a.start, b.start);
            b.end = max(a.end, b.end);
            return true;
        }
        return false;
    }

    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> ans;
        bool flag = true;
        for(int i = 0; i < intervals.size(); ++ i)
            if(!overlap(intervals[i], newInterval)) {
                if(flag && newInterval.end < intervals[i].start) {
                    ans.push_back(newInterval);
                    flag = false;
                }
                ans.push_back(intervals[i]);
            }
        if(flag)
            ans.push_back(newInterval);
        return ans;
    }
};