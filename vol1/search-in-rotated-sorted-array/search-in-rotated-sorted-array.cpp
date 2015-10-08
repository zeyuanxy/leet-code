class Solution {
public:
    int search(int A[], int n, int target) {
        int l = 0, r = n - 1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(A[mid] == target)
                return mid;
            if(A[r] >= A[l]) {
                if(A[mid] > target)
                    r = mid - 1;
                if(A[mid] < target)
                    l = mid + 1;
            }
            else {
                if(A[mid] >= A[l]) {
                    if(A[mid] > target) {
                        if(A[l] <= target)
                            r = mid - 1;
                        else
                            l = mid + 1;
                    }
                    else {
                        l = mid + 1;
                    }
                }
                else {
                    if(A[mid] < target) {
                        if(A[r] >= target)
                            l = mid + 1;
                        else
                            r = mid - 1;
                    }
                    else {
                        r = mid - 1;
                    }
                }
            }
        }
        return -1;
    }
};