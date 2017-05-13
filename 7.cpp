class Solution {
public:
    int reverse(int x) {
        int flag = 0;
        if(x < 0){
            flag = 1;
            x = -x;
        }
        vector<int> v;
        while(x > 0){
            v.push_back(x % 10);
            x /= 10;
        }
        long long res = 0;
        for(int i = 0;i < v.size();i++){
            if(flag == 0){
                res = res * 10 + v[i];
            }
            else{
                res = res * 10 - v[i];
            }
        }
        if(res > INT_MAX || res < INT_MIN)
            return 0;
        else
            return res;
    }
};