class Solution {
public:
    void dfs(TreeNode* node, int &count, vector<int>& freq) {
        if (node == nullptr)
            return;
        freq[node->val]++;
        if (!node->left && !node->right) {
            int oddCount = 0;
            for (int i = 1; i < 10; i++){
                if (freq[i] % 2 != 0) oddCount++;
            }
            if(oddCount<=1) count++;
            freq[node->val]--;
            return;
        }
        if (node->left) dfs(node->left, count, freq);
        if (node->right) dfs(node->right, count, freq);
        freq[node->val]--;
    }
    int pseudoPalindromicPaths(TreeNode* root) {
        vector<int> freq(10, 0);
        int count=0;
        dfs(root,count,freq);
        return count;
    }
};
