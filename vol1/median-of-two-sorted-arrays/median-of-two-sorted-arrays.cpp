class Solution {
public:
    double findKth(int A[], int m, int B[], int n, int k) {
        if(m > n)
            return findKth(B, n, A, m, k);
        if(m == 0)
            return B[k - 1];
        if(k == 1)
            return min(A[0], B[0]);
        int ka = min(k / 2, m), kb = k - ka;
        if(A[ka - 1] < B[kb - 1])
            return findKth(A + ka, m - ka, B, n, k - ka);
        else if(A[ka - 1] > B[kb - 1])
            return findKth(A, m, B + kb, n - kb, k - kb);
        else
            return A[ka - 1];
    }


    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if((m + n) % 2 == 1)
            return findKth(A, m, B, n, (m + n) / 2 + 1);
        else
            return (findKth(A, m, B, n, (m + n) / 2) + findKth(A, m, B, n, (m + n) / 2 + 1)) / 2;
    }
};