class Solution {
public:
    int findPos(int A[], int start, int end, int key, bool findLeft) {
        if(start > end)
            return -1;
        int mid = (start + end) / 2;
        if(A[mid] == key) {
            int pos = findLeft ? findPos(A, start, mid - 1, key, findLeft) : findPos(A, mid + 1, end, key, findLeft);
            if(pos == -1)
                return mid;
            else
                return pos;
        }
        else if(A[mid] < key)
            return findPos(A, mid + 1, end, key, findLeft);
        else
            return findPos(A, start, mid - 1, key, findLeft);
    }

    vector<int> searchRange(int A[], int n, int target) {
        vector<int> result;
        result.push_back(findPos(A, 0, n - 1, target, true));
        result.push_back(findPos(A, 0, n - 1, target, false));
        return result;
    }
};