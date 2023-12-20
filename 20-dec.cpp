class Solution {
public:
    int buyChoco(vector<int>& p, int m) {
    int m1=101,m2=101;
    for (int i=0;i<p.size();i++){
        if(p[i]<=m1){m2=m1;m1=p[i];}
        else if (p[i]<=m2)m2=p[i];
    }
    if (m>=m1+m2){return m-(m1 + m2);}
    else return m;
    }
};
