class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        vector<int> union_find(200 , -1);
        for (int i = 0;i < M.size();i++) {
            for (int j = i + 1;j < M[i].size();j++) {
                if (M[i][j] == 1) {
                    int ancestor1 = FindAncestor(union_find , i);
                    int ancestor2 = FindAncestor(union_find , j);
                    if (ancestor1 != ancestor2)
                        Union(union_find , ancestor1 , ancestor2);
                }
            }
        }
        int res = 0;
        for (int i = 0;i < M.size();i++) {
            if (union_find[i] == -1)
                res++;
        }
        return res;
    }

    int FindAncestor(vector<int> &v , int index) {
        if (v[index] == -1)
            return index;
        return v[index] = FindAncestor(v , v[index]);
    }

    void Union(vector<int> &v , int a , int b) {
        v[b] = a;
    }
};