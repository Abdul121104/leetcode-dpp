class Solution {
private:
    int ans=0;
    int solve(TreeNode* root){
        if(!root) return 0;
        int hl = solve(root->left);
        int hr= solve(root->right);
        ans=max(ans,hl+hr);
        cout<<hl<<" "<<hr<<" "<<ans;
        cout<<"\n";
        return max(hl, hr) + 1;
        // return (main==root)?max(hl,hr):max(hl,hr)+1;
}
public:
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return ans;
    }
};
