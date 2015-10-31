/* 
* @Author: Zeyuan Shang
* @Date:   2015-10-30 21:06:35
* @Last Modified by:   Zeyuan Shang
* @Last Modified time: 2015-10-30 21:06:59
*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> adjacentList(numCourses);
        vector<int> inDegree(numCourses);
        for (auto& p : prerequisites) {
            adjacentList[p.second].push_back(p.first);
            ++inDegree[p.first];
        }
       
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> ret;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            ret.push_back(v);
            for (auto t : adjacentList[v]) {
                --inDegree[t];
                if (inDegree[t] == 0) {
                    q.push(t);
                }
            }
        }
        
        if (ret.size() < numCourses) {
            return vector<int>();
        } else {
            return ret;
        }
    }
};