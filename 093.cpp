class Solution {
    public:
        vector<string> restoreIpAddresses(string s) {
            vector<string> res;

            restore(res, s, 0, 3, "", "");

            return res;
        }

        void restore(vector<string>& res, string s, int index, int remain, string s1, string s2) {
            if (s.empty())
                return;

            if (remain == 0 && index >= s.length()) {
                res.push_back(s1);
                return;
            }    
            
            if (!s2.empty() && s2[0] == '0')
                return;
                
            s1.append(1, s[index]);
            s2.append(1, s[index]);

            int t = convertToDecimal(s2);

            if (t > 255)
                return;
                
            restore(res, s, index + 1, remain, s1, s2);

            if (index < s.length() - 1 && remain > 0) {
                s1 += ".";
                restore(res, s, index + 1, remain - 1, s1, "");
            }
        }

        int convertToDecimal(string s) {
            int res = 0;

            for (int i = 0;i < s.length();i++)
                res = res * 10 + s[i] - '0';
            
            return res;
        }
};