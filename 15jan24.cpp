class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int>mpp;
        for(auto match:matches){
            if(!mpp.count(match[0])) mpp[match[0]]=0;
            mpp[match[1]]+=1;
        }
        vector<int>zeros,ones;
        for(auto it:mpp){
            if(it.second==0) zeros.push_back(it.first);
            if(it.second==1) ones.push_back(it.first);
        }
        return {zeros,ones};
    }
};