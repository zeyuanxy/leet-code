class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int n = height.size();
        if(n ==  0)
            return 0;
        int *l = new int[n], *r = new int[n];
        memset(l, 0, sizeof(int) * n);
        memset(r, 0, sizeof(int) * n);
        for(int i = 0; i < n; ++ i) {
            l[i] = i;
            while(l[i] > 0 && height[l[i] - 1] >= height[i])
                l[i] = l[l[i] - 1];
        }
        for(int i = n - 1; i >= 0; -- i) {
            r[i] = i;
            while(r[i] < n - 1 && height[r[i] + 1] >= height[i])
                r[i] = r[r[i] + 1];
        }
        int ans = 0;
        for(int i = 0; i < n; ++ i)
            ans = max(ans, (r[i] - l[i] + 1) * height[i]);
        return ans;
    }
};