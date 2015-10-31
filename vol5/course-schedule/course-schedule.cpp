/* 
* @Author: Zeyuan Shang
* @Date:   2015-10-30 21:00:21
* @Last Modified by:   Zeyuan Shang
* @Last Modified time: 2015-10-30 21:00:35
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
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
        int cnt = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            ++cnt;
            for (auto t : adjacentList[v]) {
                --inDegree[t];
                if (inDegree[t] == 0) {
                    q.push(t);
                }
            }
        }
        
        if (cnt < numCourses) {
            return false;
        } else {
            return true;
        }
    }
};