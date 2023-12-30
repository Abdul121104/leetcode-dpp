class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char,int> m;
        int n=words.size();
        for(auto s:words){
            for(auto c:s){
                m[c]++;
            }
        }
        for(auto i:m){
            if(i.second%n) return false;
        }
        return true;
    }
};
