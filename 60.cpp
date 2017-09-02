class Solution {
    public:
        string getPermutation(int n, int k) {
            vector<int> nums(n);
            vector<int> use(n, 0);

            for (int i = 0;i < n;i++)
                nums[i] = i + 1;
            
            string res = "";
            int position = 0;

            while (position < nums.size()) {
                int n = nums.size() - 1 - position;
                int n1 = 1;

                for (int i = n;i > 0;i--)
                    n1 *= i;
                
                int t = (k % n1 == 0) ? k / n1 - 1 : k / n1;
                int t1 = t;
                int index;

                for (int i = 0;i < nums.size();i++) {
                    if (use[i] == 0) {
                        if (t == 0) {
                            index = i;
                            break;
                        } else {
                            t--;
                        }
                    }
                }

                use[index] = 1;
                res.append(1, nums[index] + '0');
                k -= t1 * n1;
                position++;
            }
            
            return res;
        }
};