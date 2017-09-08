class Solution {
    public:
        int numDecodings(string s) {
            if (s.empty())
                return 0;
                
            vector<int> res(s.length() + 1, 1);

            for (int i = 0;i < s.length();i++) {
                int t1 = 0;
                int t2 = 0;

                if (s[i] != '0')
                    t1 = res[i];
                
                if (i > 0 && (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')))
                    t2 = res[i - 1];
                
                res[i + 1] = t1 + t2;
            }

            return res[s.length()];
        }
};