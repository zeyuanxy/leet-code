class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if(matrix.size() == 0)
            return false;
        int l = 0, r = matrix.size() * matrix[0].size() - 1;
        while(l <= r)
        {
            int mid = (l + r) / 2;
            int midValue = matrix[mid / matrix[0].size()][mid % matrix[0].size()];
            if(midValue == target)
                return true;
            if(midValue > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return false;
    }
};