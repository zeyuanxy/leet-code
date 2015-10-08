class Solution {
public:
    bool canJump(int A[], int n) {
        if(n == 0)
            return false;
        int ans = 0;
        for(int i = 0; i < n && i <= ans; ++ i)
            if(i + A[i] > ans)
                ans = i + A[i];
        if(ans >= n - 1)
            return true;
        else
            return false;
    }
};