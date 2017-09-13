class Solution {
    public:
        UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
            if (!node)
                return NULL;
            
            if (m.find(node) == m.end()) {
                m[node] = new UndirectedGraphNode(node->label);

                for (int i = 0;i < node->neighbors.size();i++)
                    m[node]->neighbors.push_back(cloneGraph(node->neighbors[i]));
            }

            return m[node];
        }   
    private:
        map<UndirectedGraphNode*, UndirectedGraphNode*> m;
};