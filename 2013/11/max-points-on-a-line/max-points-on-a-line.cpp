/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if(points.size() == 0)
            return 0;
            
        map<double, int> mp;
        int ans = 1;
        for(int i = 0; i < points.size(); ++ i) {
            mp.clear();
            int maxValue = 0;
            int duplicate = 1;
            for(int j = i + 1; j < points.size(); ++ j)
                if(points[i].x == points[j].x && points[i].y == points[j].y)
                    duplicate ++;
                else {
                    double k = (points[i].x == points[j].x) ? INT_MAX : (double)(points[j].y - points[i].y) / (points[j].x - points[i].x);
                    mp[k] ++;
                    maxValue = max(maxValue, mp[k]);
                }
            ans = max(ans, maxValue + duplicate);
        }
        return ans;    
    }
};