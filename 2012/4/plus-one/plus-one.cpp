class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        if(digits.size() == 0)
            return digits;
        vector<int> temp = digits;
        reverse(temp.begin(), temp.end());
        temp[0] += 1;
        for(int i = 0; i < temp.size() - 1; ++ i)
        {
            if(temp[i] > 9)
            {
                temp[i] %= 10;
                temp[i + 1] += 1;
            }
            else
                break;
        }
        if(temp[temp.size() - 1] > 9)
        {
            temp[temp.size() - 1] %= 10;
            temp.push_back(1);
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
};