class Solution {
public:
    int ans = 0;    
    bool isUnique(string str){
        set<char> st;
        for(int i=0; i<str.size(); i++){
        if (st.count(str[i])) return false;
        st.insert(str[i]);
        }
        return true;
    }
    void solve(vector<string>& arr, string str, int n, int index){
        if(!isUnique(str)) return;
        int size=str.size();
        ans=max(ans,size);
        if(index>=n)return;
        solve(arr,str+arr[index],n,index+1);
        solve(arr,str,n,index+1);
    }
    int maxLength(vector<string>& arr){
        int n=arr.size();
        string str= "";
        solve(arr,str,n,0);
        return ans;
    }
};