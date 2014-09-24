class Solution {
public:
    int singleNumber(int A[], int n) {
        int once = 0, twice = 0, no_three = 0;
        for(int i = 0; i < n; ++ i)
        {
            twice |= A[i] & once; 
            once ^= A[i];
            no_three = ~(once & twice);
            once &= no_three;
            twice &= no_three;
        }
        return once;
    }
};