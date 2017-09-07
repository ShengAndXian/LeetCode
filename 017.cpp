class Solution {
    public:
        vector<string> letterCombinations(string digits) {
            map<char, string> m;

            m['2'] = "abc";
            m['3'] = "def";
            m['4'] = "ghi";
            m['5'] = "jkl";
            m['6'] = "mno";
            m['7'] = "pqrs";
            m['8'] = "tuv";
            m['9'] = "wxyz";

            vector<string> res;
            string s = "";

            DFS(digits, 0, m, res, s);

            return res;
        }

        void DFS(string& digits, int index, map<char, string>& m, vector<string>& res, string s) {
            if (index >= digits.length()) {
                if (!s.empty())
                    res.push_back(s);
                return;
            }

            for (int i = 0;i < m[digits[index]].length();i++) {
                string str1 = s;
                string str2 = m[digits[index]];

                str1.append(1, str2[i]);

                DFS(digits, index + 1, m, res, str1);
            }
        }
};