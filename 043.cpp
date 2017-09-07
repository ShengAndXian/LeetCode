class Solution {
    public:
        string multiply(string num1, string num2) {
            vector<string> v;

            if (num1 == "0" || num2 == "0")
                return "0";
            
            for (int i = num2.length() - 1;i >= 0;i--) {
                string s = multiply1(num1, num2[i]);

                v.push_back(s);
            }

            string res = "";

            for (int i = 0;i < v.size();i++) {
                for (int j = 0;j < i;j++) {
                    v[i] += "0";
                }

                res = add(v[i], res);
            }

            return res;
        }

        string multiply1(string num1, char num2) {
            string s = "";
            int tmp = 0;

            for (int i = num1.length() - 1;i >= 0;i--) {
                int t = (num2 - '0') * (num1[i] - '0') + tmp;

                s.append(1, t % 10 + '0');
                tmp = t / 10;
            }

            if (tmp > 0) 
                s.append(1, tmp + '0');

            string res = "";

            for (int i = s.length() - 1;i >= 0;i--) 
                res.append(1, s[i]);

            return res;
        }

        string add(string num1, string num2) {
            string s = "";
            int tmp = 0;

            int i;

            for (i = 0;num1.length() > i && num2.length() > i;i++) {
                int t = num1[num1.length() - 1 - i] - '0' + num2[num2.length() - 1 - i] - '0' + tmp;

                s.append(1, t % 10 + '0');
                tmp = t / 10;
            }
            
            while (num1.length() > i) {
                int t = num1[num1.length() - 1 - i] - '0' + tmp;

                s.append(1, t % 10 + '0');
                tmp = t / 10;
                i++;
            }

            while (num2.length() > i) {
                int t = num2[num2.length() - 1 - i] - '0' + tmp;

                s.append(1, t % 10 + '0');
                tmp = t / 10;
                i++;
            }

            if (tmp > 0) 
                s.append(1, tmp + '0');
            
            string res = "";

            for (i = s.length() - 1;i >= 0;i--) 
                res.append(1, s[i]);
            
            return res;
        }
};