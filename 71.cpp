class Solution {
    public:
        string simplifyPath(string path) {
            for (int i = 0;i < path.length();i++)
                if (path[i] == '/')
                    path.replace(i, 1, " ");

            stringstream ss(path);
            string s;
            vector<string> v;

            while (ss >> s)
                v.push_back(s);

            vector<string> v1;
                
            for (int i = 0;i < v.size();i++) {
                if (v[i] != ".") {
                    if (v[i] != "..") 
                        v1.push_back(v[i]);
                    else if (!v1.empty())
                        v1.pop_back();
                }
            }

            string res;

            for (int i = 0;i < v1.size();i++)
                res += "/" + v1[i];

            return res == "" ? "/" : res;
        }
};
