class Solution {
public:
    int maxSubArray(int A[], int n) {
        if(n == 0)
            return 0;
        int sum = 0, ans = A[0];
        for(int i = 0; i < n; ++ i)
        {
            if(sum < 0)
                sum = 0;
            sum += A[i];
            if(sum > ans)
                ans = sum;
        }
        return ans;
    }
};