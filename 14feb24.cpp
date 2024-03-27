class Solution {
public:
    vector<int> rearrangeArray(vector<int>& a) {
        int n=a.size(),e=0,o=1;
        vector<int>v(n);
        for(int i=0;i<n;i++){
            if(a[i]<0){v[o]=a[i];o+=2;}
            else {v[e]=a[i];e+=2;}
        }
        return v;
    }
};
