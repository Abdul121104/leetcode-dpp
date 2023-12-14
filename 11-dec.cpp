class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int,int> m;
        int n=arr.size();
        int t=n/4;
        for(int i=0;i<n;i++){m[arr[i]]++;if(m[arr[i]]>t) return arr[i];}
        return -1;
    }
};
