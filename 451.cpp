class Solution {
public:
    struct node {
        char c;
        int count;
    };
    string frequencySort(string s) {
        vector<node> record(255);
        for (int i = 0;i < 255;i++) {
            record[i].count = 0;
        }
        for (int i = 0;i < s.length();i++) {
            int index = s[i];
            record[index].count++;
            record[index].c = s[i];
        }
        sort(record.begin() , record.end() , cmp);
        string res = "";
        for (int i = 0;i < 255;i++) {
            if (record[i].count == 0)
                break;
            for (int j = 0;j < record[i].count;j++) {
                res += record[i].c;
            }
        }
        return res;
    }
    static bool cmp(node a , node b) {
        return a.count > b.count;
    }
};