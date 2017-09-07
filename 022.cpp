class Solution {
    public:
        vector<string> generateParenthesis(int n) {
            vector<string> res;

            combinate(res, "", 0, 0, 0, n);

            return res;
        }

        void combinate(vector<string>& res, string s, int index, int numOfLeft, int numOfUnpairedLeft, int n) {
            if (index == 0) {
                numOfLeft++;
                numOfUnpairedLeft++;

                s += "(";
            } else {
                numOfUnpairedLeft--;

                s += ")";
            }

            if (numOfLeft != n)
                combinate(res, s, 0, numOfLeft, numOfUnpairedLeft, n);
            
            if (numOfUnpairedLeft > 0) 
                combinate(res, s, 1, numOfLeft, numOfUnpairedLeft, n);

            if (numOfLeft == n && numOfUnpairedLeft == 0) 
                res.push_back(s);
        }
};