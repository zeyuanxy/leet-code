/* 
* @Author: Zeyuan Shang
* @Date:   2015-12-03 00:50:03
* @Last Modified by:   Zeyuan Shang
* @Last Modified time: 2015-12-03 00:50:12
*/

struct Candidate {
    int index, value, prime;
    bool operator<(const Candidate& c) const {
        return value > c.value;
    }   
};

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ret;
        int k = primes.size();
        priority_queue<Candidate> pq;
        for (int i = 0; i < k; ++i) {
            Candidate c;
            c.index = 0;
            c.value = 1;
            c.prime = primes[i];
            pq.push(c);
        }
        for (int i = 0; i < n; ++i) {
            int nextValue = pq.top().value;
            ret.push_back(nextValue);
            while (pq.top().value == nextValue) {
                Candidate c = pq.top();
                pq.pop();
                c.value = ret[c.index] * c.prime;
                c.index++;
                pq.push(c);
            }
        }
        return ret.back();
    }
};