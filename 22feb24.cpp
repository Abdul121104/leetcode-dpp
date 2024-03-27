class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> f1(n+2), f2(n+2);
        for (int i=0;i<trust.size();i++) {
            f1[trust[i][0]]++;
            f2[trust[i][1]]++;
        }
        for (int i=1;i<=n;i++) {
            if (f1[i]==0&&f2[i]==n-1){
                return i;
            }
        }
        return -1;
    }
};
