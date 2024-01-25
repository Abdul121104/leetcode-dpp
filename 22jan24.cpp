class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size(),d,m;
        vector<bool> v(n+1);
        for(int i=0;i<n;i++){
            if(v[nums[i]]) d=nums[i];
            else v[nums[i]]=true;
        }
        for(int i=1;i<v.size();i++){
            if(!v[i]) {m=i;break;}
        }
        return {d,m};
    }
};