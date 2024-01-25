class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int ,int> m;
        set<int> count;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]++;
        }
        for(auto x:m){
        if(count.count(x.second)) return false;
        count.insert(x.second);
    }
    return true;
    }
};