class Solution {
public:
    string convert(string s, int numRows) {
        int row = 0;
        vector<string> v(numRows);
        if(numRows == 1)
            return s;
        for(int i = 0;i < s.length();i++){
            row++;
            if(row <= numRows){
                v[row - 1] += s[i];
            }
            else{
                v[numRows - 1 - (row - numRows)] += s[i];
            }
            if(row - numRows == numRows - 2)
                row = 0;
        }
        string res;
        for(int i = 0;i < numRows;i++){
            res += v[i];
        }
        return res;
    }
};