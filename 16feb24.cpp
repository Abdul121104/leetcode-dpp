class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> m;
        for (int i = 0; i < arr.size(); i++)
            m[arr[i]]++;
        vector<pair<int,int>> v;
        for (auto x : m){
            v.push_back(make_pair(x.second,x.first));
        }
        int ans=v.size();
        sort(v.begin(),v.end());
        for (int i=0;i<v.size();i++) {
            if(v[i].first<=k){
                k-=v[i].first;
                ans--;
            }
        }
        return ans;
    }
};
