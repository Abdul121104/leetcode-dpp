class Solution {
public:
    int pivotInteger(int n) {
        int sum = n*(n+1)/2;
        int x = sqrt(sum);
        float xf = sqrt(sum);
        return (x == xf) ? x : -1;
    }
};
