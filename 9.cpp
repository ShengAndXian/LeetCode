class Solution {
public:
    bool isPalindrome(int x) {
        vector<int> v;
        if(x < 0)
            return false;
        while(x > 0){
            v.push_back(x % 10);
            x /= 10; 
        }
        int i , j;
        for(i = 0,j = v.size() - 1;i <= j;i++,j--){
            if(v[i] != v[j])
                return false;
        }
        return true;
    }
};