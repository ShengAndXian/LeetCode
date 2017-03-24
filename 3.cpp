class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int flag[300] = {0};
        int cnt = 0;
        int max = 0;
        int i , j;
        int pre = 0;
        for(i = 0;i < s.length();i++){
            if(i != 0){
                flag[s[i - 1]]--;
                cnt--;
            }
            for(j = pre;j < s.length();j++){
                if(flag[s[j]] == 0){
                    flag[s[j]]++;
                    cnt++;
                }
                else{
                    pre = j;
                    break;
                }
            }
            if(cnt > max){
                max = cnt;
            }
        }
        return max;
    }
};