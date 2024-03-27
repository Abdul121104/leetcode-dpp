class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<long long> v;
        v.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            v.push_back(nums[i]+v[i-1]);
        }
        for(int i=nums.size()-1;i>1;i--)
            if(nums[i]<v[i-1]) return v[i];
        return -1;
    }
};
