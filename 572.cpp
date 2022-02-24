/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool compareTree_1(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*> q_root;
        q_root.push(root);
        queue<TreeNode*> q_subRoot;
        q_subRoot.push(subRoot);
        while (!q_subRoot.empty() && !q_root.empty()){
            TreeNode* tn_subRoot = q_subRoot.front();
            q_subRoot.pop();
            TreeNode* tn_root = q_root.front();
            q_root.pop();
            if (tn_subRoot->val != tn_root->val) {return false;}
            if (!tn_subRoot->left && tn_root->left) {return false;}
            if (tn_subRoot->left && !tn_root->left) {return false;}
            if (!tn_subRoot->right && tn_root->right) {return false;}
            if (tn_subRoot->right && !tn_root->right) {return false;}
            else {
                if (tn_subRoot->left) {q_subRoot.push(tn_subRoot->left);}
                if (tn_subRoot->right) {q_subRoot.push(tn_subRoot->right);}
                if (tn_root->left) {q_root.push(tn_root->left);}
                if (tn_root->right) {q_root.push(tn_root->right);}
            }
        }
        return q_subRoot.empty() && q_root.empty();
    }
    
    bool compareTree_2(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) return true;
        if (!root || !subRoot || root->val != subRoot->val) {return false;}
        return compareTree_2(root->left, subRoot->left) && compareTree_2(root->right, subRoot->right);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            TreeNode* tn = q.front();
            q.pop();
            if (tn->val == subRoot->val) {
                // ans = compareTree_1(tn, subRoot);
                ans = compareTree_2(tn, subRoot);
                if (ans) {return ans;}
            }
            if (tn->left) {q.push(tn->left);}
            if (tn->right) {q.push(tn->right);}
        }
        return false;
    }
};