class Solution{
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k){
        int n=nums.size();
        int r=n/3;
        int w=0;
        vector<vector<int>> result;
        if(n%3!=0) return result;
        sort(nums.begin(),nums.end());
        for(int i=0;i<=n-3;i+=3) if(nums[i+2]-nums[i]>k) return result;
        for(int i=0;i<r;++i){
            vector<int> currentArray;
            for(int j=0;j<3;++j){
                currentArray.push_back(nums[w]);
                ++w;
            }
            result.push_back(currentArray);
        }
        return result;
    }
};
