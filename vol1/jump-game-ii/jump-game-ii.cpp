class Solution {
public:
    int jump(int A[], int n) {
        int i = 1;
        int maxPos = A[0], nextMaxPos = 0;
        int ans = 0;
        while(i < n) {
            while(i < n && i <= maxPos) {
                nextMaxPos = max(nextMaxPos, i + A[i]);
                ++ i;
            }
            ans ++;
            maxPos = nextMaxPos;
        }
        return ans;
    }
};