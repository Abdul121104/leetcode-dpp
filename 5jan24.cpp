class Solution {
public:
    int lower_bound_bs(vector<int> &a, int target){
        int indx;
        int l = 0, h = a.size() - 1;
        while(h-l > 1){
            int mid = (h+l)/2;
            if(a[mid] < target)
                l = mid+1;
            else
                h = mid;
        }
        if(a[l] >= target) indx = l;
        else indx = h;
        return indx;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v;
        for(auto x: nums){
            if(v.empty() || v[int(v.size()) - 1] < x)
                v.push_back(x);
            else{
                int l_b = lower_bound_bs(v, x);
                v[l_b] = x;
            }
        }
        return int(v.size());
    }
};