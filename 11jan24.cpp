class Solution {
public:
    int ans=0;
    void findDiff(TreeNode* root, int mini, int maxi)
    {
        if(root == nullptr) return;
        maxi = max(maxi, root->val);
        mini = min(mini, root->val);
        ans = max(ans, maxi-mini);
        findDiff(root->left, mini, maxi);
        findDiff(root->right, mini, maxi);
    }
    int maxAncestorDiff(TreeNode* root) {
        int mini = root->val, maxi = root->val;
        findDiff(root, mini, maxi) ;
        return ans;
    }
};