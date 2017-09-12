class Solution {
    public:
        vector<vector<string>> partition(string s) {
            vector<vector<string> > res;
            vector<string> v;

            partition1(s, 0, res, v);

            return res;
        }

        void partition1(string s, int index, vector<vector<string> >& res, vector<string> v) {
            if (index >= s.length()) {
                res.push_back(v);
                return;
            }

            string s1;

            while (index < s.length()) {
                s1.append(1, s[index]);

                if (isPalindrome(s1)) {
                    v.push_back(s1);
                    partition1(s, index + 1, res, v);
                    v.pop_back();
                }

                index++;
            }
        }

        bool isPalindrome(string s) {
            int start = 0;
            int end = s.length() - 1;

            while (start <= end) {
                if (s[start] != s[end])
                    return false;
                
                start++;
                end--;
            }

            return true;
        }
};