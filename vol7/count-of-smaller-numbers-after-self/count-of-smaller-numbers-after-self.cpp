/* 
* @Author: Zeyuan Shang
* @Date:   2015-12-07 01:11:23
* @Last Modified by:   Zeyuan Shang
* @Last Modified time: 2015-12-07 01:11:29
*/

class Solution {
public:
    int lowbit(int x) {
        return x & (-x);
    }
    
    int update(vector<int>& bit, int index, int x) {
        int n = bit.size();
        for (int j = index; j < n; j += lowbit(j)) {
            bit[j] += x;
        }
    }
    
    int sum(vector<int>& bit, int index) {
        int ret = 0;
        for (int j = index; j > 0; j -= lowbit(j)) {
            ret += bit[j];
        }
        return ret;
    }

    vector<int> countSmaller(vector<int>& nums) {
        if (nums.empty()) {
            return vector<int>();
        }
        
        int n = nums.size();
        vector<pair<int, int>> elements;
        for (int i = 0; i < n; ++i) {
            elements.push_back(make_pair(nums[i], i));
        }
        sort(elements.begin(), elements.end());
        
        vector<int> count(n), ans(n);
        count[elements[0].second] = 1;
        for (int i = 1; i < n; ++i) {
            if (elements[i].first == elements[i - 1].first) {
                count[elements[i].second] = count[elements[i - 1].second];
            } else {
                count[elements[i].second] = count[elements[i - 1].second] + 1;
            }
        }
        
        vector<int> bit(n + 1);
        for (int i = n - 1; i >= 0; --i) {
            update(bit, count[i], 1);
            ans[i] = sum(bit, count[i] - 1);
        }
        return ans;
    }
};