class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row1, row2;
        for(int i = 0; i <= rowIndex; ++ i)
        {
            row1.push_back(0);
            row2.push_back(0);
        }
        row1[0] = 1;
        for(int i = 1; i <= rowIndex; ++ i)
        {
            row2[0] = 1;
            for(int j = 1; j <= i; ++ j)
                row2[j] = row1[j - 1] + row2[j];
            row1 = row2;
        }
        return row1;
    }
};