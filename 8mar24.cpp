class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int ,int> m;
        int maxx=0;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
            maxx=max(maxx,m[nums[i]]);
        }
        int freq=0;
        for(auto x:m){
            if(x.second==maxx){
                freq+=x.second;
            }
        }
        return freq;
    }
};
