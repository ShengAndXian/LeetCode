class Solution {
    public:
        bool wordBreak(string s, vector<string>& wordDict) {
            sort(wordDict.begin(), wordDict.end());

            vector<bool> v(s.length() + 1, false);
            v[0] = true;

            for (int i = 0;i < s.length();i++) {
                for (int j = i;j >= 0;j--) {
                    if (v[j] && binary_search(wordDict.begin(), wordDict.end(), s.substr(j, i - j + 1))) {
                        v[i + 1] = true;
                        break;
                    }
                }
            }

            return v[s.length()];
        }
};