class Solution {
public:
    void heapify(int i, int n, vector<int> &nums) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largestIndex = i;

        if (left < n && nums[left] > nums[largestIndex])
            largestIndex = left;
        if (right < n && nums[right] > nums[largestIndex])
            largestIndex = right;

        if (largestIndex != i) {
            swap(nums[largestIndex], nums[i]);
            heapify(largestIndex, n, nums);
        }
    }

    void createHeap(vector<int> &nums) {
        int n = nums.size();

        for (int i = n / 2 - 1; i >= 0; --i) {
            heapify(i, n, nums);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        createHeap(nums);
        
        int n = nums.size();
        for (int i = n - 1; i >= 1; --i) {
            swap(nums[0], nums[i]); 
            heapify(0, i, nums);  
        }
        
        return nums;
    }
};
