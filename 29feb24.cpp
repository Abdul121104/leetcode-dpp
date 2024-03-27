class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        std::vector<std::vector<int>> res;
        std::queue<TreeNode*> q;
        if (root) {
            q.push(root);
        }

        while (!q.empty()) {
            int size = q.size();
            std::vector<int> levelValues;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                levelValues.push_back(node->val);

                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }

            res.push_back(levelValues);
        }

        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++) {
                if (i % 2 == 0){
                    if (j>0 && res[i][j]<=res[i][j-1])
                        return false;
                    if (res[i][j] % 2 == 0)
                        return false;
                            }
                else {
                    if (j>0 && res[i][j]>=res[i][j-1])
                        return false;
                    if (res[i][j]%2==1)
                        return false;
                }
            }
        }
        return true;
    }
};
