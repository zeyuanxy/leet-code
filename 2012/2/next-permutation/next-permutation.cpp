class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int n = num.size(), i, j;
        for(i = n - 1; i > 0; -- i)
            if(num[i] > num[i - 1])
                break;
        if(i == 0)
        {
            sort(num.begin(), num.end());
            return;
        }
        for(j = n - 1; j >= i; -- j)
            if(num[j] > num[i - 1])
                break;
        swap(num[j], num[i - 1]);
        reverse(num.begin() + i, num.end());
    }
};