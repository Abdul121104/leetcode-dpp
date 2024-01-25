class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int ,int> m;
        int ans=0;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]++;
        
        for(auto x:m){
            if(x.second==1) return -1;
            ans+=ceil((double)x.second/3);
        }
        return ans;
    }
};