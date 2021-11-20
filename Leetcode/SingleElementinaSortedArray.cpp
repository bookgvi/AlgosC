class SingleElementInArray {
public:
    int singleNonDuplicate(vector<int> &nums) {
        int last = (int) nums.size() - 1;
        if (last == 0 || last == 1) return nums[last];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[last] != nums[last - 1]) return nums[last];
        for (int i = 2; i <= last >> 1; i += 1) {
            int j = last - i;
            if (nums[i] > nums[i - 1] && nums[i] < nums[i + 1])
                return nums[i];
            if (nums[j] < nums[j + 1] && nums[j] > nums[j - 1])
                return nums[j];
        }
        return 0;
    }

    void work() {
        vector<int> nums = {1, 1, 2, 3, 3};
        int res = singleNonDuplicate(nums);
    }
};