class Solution {
public:
    bool search(int A[], int n, int target) {
        int l = 0, r = n - 1;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(target == A[mid])
                return true;
            if(A[l] == A[mid]  && A[mid] == A[r]) {
                l ++;
                r --;
            }
            else if(A[l] <= A[mid]) {
                if(A[l] <= target && target < A[mid]) {
                    r = mid - 1;
                }
                else
                    l = mid + 1;
            }
            else {
                if(A[mid] < target && target <= A[r])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return false;
    }
};