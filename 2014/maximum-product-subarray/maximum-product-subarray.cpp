class Solution {
public:
    int maxProduct(int A[], int n) {
        if (n <= 0)
            return 0;
        int max_ = A[0], min_ = A[0], ans = A[0];
        for (int i = 1; i < n; ++i) {
            max_ *= A[i];
            min_ *= A[i];
            ans = max(ans, max(max(max_, min_), A[i]));
            if (max_ < min_)
                swap(max_, min_);
            max_ = max(max_, A[i]);
            min_ = min(min_, A[i]);
        }
        return ans;
    }
};