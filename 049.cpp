class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            map<string, vector<string> > m;

            for (int i = 0;i < strs.size();i++) {
                vector<char> v(strs[i].begin(), strs[i].end());

                sort(v.begin(), v.end(), less<char>());

                string s(v.begin(), v.end());

                m[s].push_back(strs[i]);
            }

            vector<vector<string> > res;
            map<string, vector<string> >::iterator it;

            for (it = m.begin();it != m.end();it++) 
                res.push_back(it->second);
            
            return res;
        }
};