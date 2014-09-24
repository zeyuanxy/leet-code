/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL)    
            return node;
        map<UndirectedGraphNode*, UndirectedGraphNode*> m;
        queue<UndirectedGraphNode*> q;
        m[node] = new UndirectedGraphNode(node->label);
        q.push(node);
        while(!q.empty()) {
            UndirectedGraphNode *top = q.front();
            q.pop();
            for(int i = 0; i < top->neighbors.size(); ++ i) {
                if(m.find(top->neighbors[i]) == m.end()) {
                    m[top->neighbors[i]] = new UndirectedGraphNode(top->neighbors[i]->label);
                    q.push(top->neighbors[i]);
                }
                m[top]->neighbors.push_back(m[top->neighbors[i]]);
            }
        }
        return m[node];
    }
};