class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        map<int,int> m;
        for(int i=0;i<n;i++) m[nums[i]]++;
        while(n>0){
            vector<int>v;
            for(auto &x:m){
                if(x.second>0){
                v.push_back(x.first);
                n--;
                x.second--;
                if(n<=0) break;
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};