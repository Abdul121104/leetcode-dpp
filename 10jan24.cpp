class Solution {
public:
    pair<bool,int> infectTree(TreeNode* root, int &x, int &max_d){
        if(root==NULL) return {false,0};
        pair<bool,int> left= infectTree(root->left,x,max_d);
        pair<bool,int> right= infectTree(root->right,x,max_d);
        if(root->val==x){
            max_d= max(left.second,right.second);
            return {true,0};
        }
        if(left.first){
            max_d= max(left.second+right.second+1,max_d);
            return {true,left.second+1};
        }
        if(right.first){
            max_d= max(left.second+right.second+1,max_d);
            return {true,right.second+1};
        }
        return {false,max(left.second,right.second)+1};
    }
    int amountOfTime(TreeNode* root, int start) {
        if(root==NULL) return 0;
        int max_d=0;
        infectTree(root,start,max_d);
        return max_d;
    }
};