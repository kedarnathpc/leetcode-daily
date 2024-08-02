class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size(), countZero = 0, i = 0, h = 0;
        int totalOnes = count(nums.begin(), nums.end(), 1);

        for (int j = 0; j < n; ++j)
            nums.push_back(nums[j]);

        while (i < totalOnes) {
            if (nums[i] == 0)
                countZero++;
            i++;
        }

        int miniZero = countZero;

        while (i < 2 * n) {
            if (nums[i] == 0)
                countZero++;
            if (nums[h] == 0)
                countZero--;
            miniZero = min(miniZero, countZero);
            i++, h++;
        }

        return miniZero;
    }
};
