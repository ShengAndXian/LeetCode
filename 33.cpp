#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty())
            return -1;
        int left = 0 , right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[mid + 1]) {
                left = mid;
                break;
            }
            else if (nums[mid] > nums[nums.size() - 1]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        if (left > right)
            return BinarySearch(nums , 0 , nums.size() - 1 , target);
        else if (target >= nums[0])
            return BinarySearch(nums , 0 , left , target);
        else
            return BinarySearch(nums , left + 1 , nums.size() - 1 , target);
    }
    int BinarySearch(vector<int> &nums , int start , int end , int target) {
        while (start <= end) {
            int mid = (start + end) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                end = mid - 1;
            else
                start = mid + 1;
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> nums(3,0);
    int target = 1;
    s.search(nums , target);
}