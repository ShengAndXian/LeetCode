class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = strs.empty() ? "" : strs[0];
        for (int i = 1; i < strs.size(); ++i) {
            if (strs[i] == "")
                return "";
            for (int j = 0; j < s.length() && j < strs[i].length(); ++j) {
                if (strs[i][j] != s[j]) {
                    s = s.substr(0 , j);
                    break;
                }
                else if (j == strs[i].length() - 1) {
                    s = s.substr(0 , j + 1);
                }
            }
        }
        return s;
    }
};