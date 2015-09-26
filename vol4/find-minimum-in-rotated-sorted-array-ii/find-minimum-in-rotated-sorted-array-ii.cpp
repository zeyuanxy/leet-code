class Solution {
  public:
        int findMin(vector<int> &num) {
                  int l = 0, r = num.size() - 1;
                          while (l < r) {
                                        if (num[l] < num[r])
                                                          break;
                                                    int mid = (l + r) >> 1;
                                                                if (num[l] == num[mid] && num[mid] == num[r]) {
                                                                                  ++l;
                                                                                                  --r;
                                                                                                                  continue;
                                                                                                                              }
                                                                            if (num[mid] >= num[l]) {
                                                                                              l = mid + 1;
                                                                                                          } else {
                                                                                                                            r = mid;
                                                                                                                                        }
                                                                                    }
                                  return num[l];
                                      }
};
