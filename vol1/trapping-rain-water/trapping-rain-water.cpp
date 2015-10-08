class Solution {
public:
    int trap(int A[], int n) {
        if(n == 0)
            return 0;
        vector<int> leftMostHeight(n);
        int maxHeight = 0;
        for(int i = 0; i < n; ++ i) {
            leftMostHeight[i] = maxHeight;
            maxHeight = max(maxHeight, A[i]);
        }
        maxHeight = 0;
        vector<int> rightMostHeight(n);
        for(int i = n - 1; i >= 0; -- i) {
            rightMostHeight[i] = maxHeight;
            maxHeight = max(maxHeight, A[i]);
        }
        
        int ans = 0;
        for(int i = 0; i < n; ++ i) 
            ans += max(min(leftMostHeight[i], rightMostHeight[i]) - A[i], 0);
        return ans;
    }
};