class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        vector<int> v;
        while(l<=r){
            if(abs(nums[l])>=abs(nums[r])) {
                v.push_back(nums[l]*nums[l]);
                l++;
            }
            else {
                v.push_back(nums[r]*nums[r]);
                r--;
            }
        }
        reverse(v.begin(),v.end());
        return v;
    }
};
