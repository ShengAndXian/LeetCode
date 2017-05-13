class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = -1;
        int left = 0 , right = height.size() - 1;
        while (left <= right) {
            int min_height = height[left] < height[right] ? height[left] : height[right];
            int contain = min_height * (right - left);
            if (contain > res)
                res = contain;
            if (min_height == height[left])
                left++;
            else
                right--;
        }
        return res;
    }
};