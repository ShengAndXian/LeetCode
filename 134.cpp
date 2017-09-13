class Solution {
    public:
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
            int n = gas.size();

            for (int i = 0;i < n;) {
                int remain = 0;
                int j;

                for (j = 0;j < n;j++) {
                    int index = (i + j) % n;

                    remain += gas[index] - cost[index];

                    if (remain < 0)
                        break;
                }

                if (j == n)
                    return i;
                
                i += j + 1;
            }

            return -1;
        }
};