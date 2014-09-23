class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if(n == 0)
            return 0;
        if(target == A[n / 2])
            return n / 2;
        if(target > A[n / 2])
            return n > 1 ? (n / 2 + searchInsert(A + n / 2, n - n / 2, target)) : 1;
        else
            return searchInsert(A, n / 2, target);
    }
};