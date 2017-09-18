class Solution {
    public:
        int compareVersion(string version1, string version2) {
            vector<int> v1;
            vector<int> v2;

            convert(v1, version1);
            convert(v2, version2);

            if (v1 == v2)
                return 0;
            else
                return v1 > v2 ? 1 : -1;
        }

        void convert(vector<int>& v, string s) {
            string s1;

            for (int i = 0;i < s.size();i++) {
                if (s[i] != '.') {
                    s1 += s[i];
                } else {
                    v.push_back(stoi(s1));
                    s1 = "";
                }
            }

            v.push_back(stoi(s1));

            while (!v.empty() && v[v.size() - 1] == 0)
                v.pop_back();
        }
};