class Solution {
public:
    int myAtoi(string str) {
        int start = 0;
        int flag = 0;
        while(start < str.length() && str[start] == ' ')
            start++;
        if(str[start] == '-' || str[start] == '+'){
            flag = str[start] == '-' ? 1 : 0;
            start++;
        }
        while(start < str.length() && str[start] == 0)
            start++;
        long long res = 0;
        for(int i = start;i < str.length();i++){
            if(str[i] >= '0' && str[i] <= '9'){
                if(flag == 0)
                    res = res * 10 + (str[i] - '0');
                else
                    res = res * 10 - (str[i] - '0');
                if(res > INT_MAX)
                    return INT_MAX;
                else if(res < INT_MIN)
                    return INT_MIN;
            }
            else
                return res;
        }
        return res;
    }
};