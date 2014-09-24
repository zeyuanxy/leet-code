class Solution {
public:
    void sortColors(int A[], int n) {
        int j = 0, k = n - 1;
        for(int i = 0; i <= k;)
        {
            if(A[i] == 0)
            {
                if(i == j)
                    ++ i;
                else
                    swap(A[i], A[j]);
                ++ j;
            }
            else if(A[i] == 2)
            {
                if(i == k)
                    ++ i;
                else
                    swap(A[i], A[k]);
                -- k;
            }
            else
                ++ i;
        }
    }
};