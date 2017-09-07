class Solution {
public:
    string longestPalindrome(string s) {
        int max = -1;
        int index;
        string res;
        for(int i = 0;i < s.length();i++){
            string tmp;
            int j , k;
            int len1 = 1;
            for(j = i - 1,k = i + 1;j >= 0 && k <= s.length() - 1;j--,k++){
                if(s[j] == s[k])
                    len1 += 2;
                else
                    break;
            }
            if(len1 > max){
                max = len1;
                index = ++j;
            }
            int len2 = 0;
            for(j = i,k = i + 1;j >= 0 && k <= s.length() - 1;j--,k++){
                if(s[j] == s[k])
                    len2 += 2;
                else
                    break;
            }
            if(len2 > max){
                max = len2;
                index = ++j;
            }
        }
        return s.substr(index , max);
    }
};