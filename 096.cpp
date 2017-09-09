class Solution {
    public:
        int numTrees(int n) {
            vector<int> count(n + 1, 0);

            count[0] = 1;
            count[1] = 1;

            for (int i = 2;i <= n;i++) 
                for (int j = 1;j <= i;j++) 
                    count[i] += count[j - 1] * count[i - j];
            
            return n == 0 ? 0 : count[n];
        }
};