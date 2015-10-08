class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() <= 1) {
            return 0;
        }
        int max_num = nums[0], min_num = nums[0];
        for (auto num : nums) {
            max_num = max(max_num, num);
            min_num = min(min_num, num);
        }
        double interval = (max_num - min_num) / nums.size() + 1;
        vector<pair<int, int>> bucket(nums.size(), make_pair(-1, -1));
        for (auto num : nums) {
            int index = (num - min_num) / interval;
            if (bucket[index].first == -1) {
                bucket[index] = make_pair(num, num);
            } else {
                bucket[index].first = min(bucket[index].first, num);
                bucket[index].second = max(bucket[index].second, num);
            }
        }
        int ret = 0, prev = bucket[0].second;
        for (int i = 1; i < nums.size(); ++i) {
            if (bucket[i].first != -1) {
                ret = max(ret, bucket[i].first - prev);
                prev = bucket[i].second;
            }
        }
        return ret;
    }
};