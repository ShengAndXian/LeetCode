class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            int mid = binarySearch1(nums, 0, nums.size() - 1, target);

            vector<int> res;

            if (mid == -1) {
                res.push_back(-1);
                res.push_back(-1);
                
                return res;
            }

            int up = binarySearch2(nums, mid + 1, nums.size() - 1, target);
            int down = binarySearch3(nums, 0, mid - 1, target);

            res.push_back(down);
            res.push_back(up);

            return res;
        }

        int binarySearch1(vector<int>& nums, int start, int end, int target) {
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

        int binarySearch2(vector<int>& nums, int start, int end, int target) {
            while (start <= end) {
                int mid = (start + end) / 2;

                if (nums[mid] == target)
                    start = mid + 1;
                else
                    end = mid - 1;
            }

            return start - 1;
        }

        int binarySearch3(vector<int>& nums, int start, int end, int target) {
            while (start <= end) {
                int mid = (start + end) / 2;

                if (nums[mid] == target)
                    end = mid - 1;
                else
                    start = mid + 1;
            }

            return end + 1;
        }
};