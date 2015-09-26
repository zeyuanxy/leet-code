class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int tail = 0;
        for(int i = 0; i < n; ++ i)
            if(A[i] != elem)
            {
                A[tail] = A[i];
                tail ++;
            }
        return tail;
    }
};