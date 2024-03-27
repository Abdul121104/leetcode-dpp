class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
    int count = 0;
    int sum = 0;
    unordered_map<int, int> prefixSumCount;
    prefixSumCount[0] = 1;
    for (int num : nums) {
        sum += num;
        count += prefixSumCount[sum - goal];
        prefixSumCount[sum]++;
    }

    return count;
    }
};
