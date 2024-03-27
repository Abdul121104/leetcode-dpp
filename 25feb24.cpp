class Solution {
public:
#define MAXN 100001
int spf[MAXN];
#define vint vector<int>
void primeFactorizationsieve()
{
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++)
        spf[i] = i;

    for (int i = 4; i < MAXN; i += 2)
        spf[i] = 2;
 
    for (int i = 3; i * i < MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXN; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}
vint getFactorization(int x)
{
    vector<int>ret;
    unordered_map<int,int>mp;
    while (x != 1) {
        mp[spf[x]]++;
        x = x / spf[x];
    }
    for(auto &it:mp)ret.push_back(it.first);
    return ret;
}

void fn(unordered_map<int,set<int>>&adj,int node,vector<int>&vis){
    vis[node] = 1;
    for(auto &it:adj[node]){
        if(!vis[it])fn(adj,it,vis);
    }
}

    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return 1;
        cout << n << " ";
        primeFactorizationsieve();

        unordered_map<int,vector<int>>prime;
        for(int i = 0;i < n;i++){
            if(nums[i] == 1)return 0;
            vint temp = getFactorization(nums[i]);
            prime[i] = temp;
        }

        unordered_map<int,vector<int>>mp1;
        for(auto &it:prime){
            int ind = it.first;
            for(auto &j:it.second)mp1[j].push_back(ind);
        }

        unordered_map<int,set<int>>adj;

        for(auto &it:mp1){
            int u = it.first;
            auto &v = it.second;
            for(int j = 1;j < v.size();j++){
                adj[v[j]].insert(v[j-1]);
                adj[v[j-1]].insert(v[j]);
            }
        }

        vector<int>vis(n,0);
        int cnt = 0;

        for(int i = 0;i < n;i++){
            if(!vis[i]){
                if(cnt == 1)return 0;
                cnt++;
                fn(adj,i,vis);
            }
        }
        return (cnt == 1) ? 1 : 0;
    }
};
