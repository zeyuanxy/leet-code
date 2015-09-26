class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n == 0)
            return 0;
        int tail = 0;
        for(int i = 1; i < n; ++ i)
            if(A[i] != A[tail])
            {
                tail ++;
                A[tail] = A[i];
            }
        return tail + 1;
    }
};