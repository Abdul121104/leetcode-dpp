class Solution {
public:
    void preorder(TreeNode* root1, vector<int> &v1) {
        if (root1 == NULL) return;
        if (root1->left == NULL && root1->right == NULL) {v1.push_back(root1->val);return;}
        preorder(root1->left, v1);
        preorder(root1->right, v1);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1,v2;
        preorder(root1,v1);
        preorder(root2,v2);
        return v1==v2;
    }
};