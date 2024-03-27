class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ans=0,c1=0,c0=0;
        map<int,int>dm{{0,-1}};
        for (int i=0;i<nums.size();i++){
            if (nums[i]==1)c1++;
            else c0++;
            int diff=c1-c0;
            if (dm.find(diff)!=dm.end())
                ans=max(ans,i-dm[diff]);
            else
                dm[diff]=i;
        }
        return ans;
        // int ps=0,ans=0;
        // unordered_map<int,int>m{{0,-1}};
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==1)
        //     ps=ps+1;
        //     else
        //     ps=ps-1;
        //     if(m.count(ps)){
        //         ans=max(ans,i-m[ps]);
        //     }
        //     else
        //     m[ps]=i;
        // }
        // return ans;
    }
};
