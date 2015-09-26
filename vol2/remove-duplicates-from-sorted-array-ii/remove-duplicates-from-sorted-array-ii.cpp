class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n == 0)
            return 0;
        int length = 0, times = 1;
        for(int i = 1; i < n; ++ i) {
            if(A[i] == A[i - 1]) {
                times += 1;
            }
            else {
                if(times > 2)
                    times = 2;
                for(int j = 0; j < times; ++ j)
                    A[length + j] = A[i - 1];
                length += times;
                times = 1;
            }
        }
        if(times > 2)
            times = 2;
        for(int j = 0; j < times; ++ j)
            A[length + j] = A[n - 1];
        length += times;
        return length;
    }
};