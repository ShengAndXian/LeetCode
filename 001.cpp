class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v(nums);
        vector<int> res;

        sort(v.begin() , v.end());
        int i = 0 , j = v.size() - 1;
        while(i <= j){
            if(v[i] + v[j] == target)
                break;
            else if(v[i] + v[j] > target)
                j--;
            else
                i++;
        }
        int k;
        for(k = 0;k < nums.size();k++){
            if(nums[k] == v[i]){
                res.push_back(k);
                break;
            }
        }
        for(k = nums.size() - 1;k >= 0;k--){
            if(nums[k] == v[j]){
                res.push_back(k);
                break;
            }
        }
        sort(res.begin() , res.end());
        return res;
    }
};