class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> result;
        if (nums.empty())
            return result;
        sort(nums.begin(),nums.end());
        vector<vector<int>> dp(nums.size(),vector<int>());
        for (int i=nums.size()-1;i>=0;--i) {
            for (int j=i+1;j<nums.size();++j){
                if (nums[j]%nums[i]==0 && dp[j].size()>dp[i].size()){
                    dp[i]=dp[j];
                }
            }
            dp[i].push_back(nums[i]);
        }
        for (const vector<int>& subset : dp) {
            if (subset.size() > result.size()) {
                result = subset;
            }
        }
        return result;
    }
};
