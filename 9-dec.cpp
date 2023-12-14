class Solution {
public:
    vector<int> n;
    vector<int> inorderTraversal(TreeNode* root){
    if(root==nullptr)return n;//check it root is empty 
    inorderTraversal(root->left);
    n.push_back(root->val);
    inorderTraversal(root->right); 
    return n;}};
