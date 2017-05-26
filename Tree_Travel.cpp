/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        //post_recursive(root,res);
        //post_iterative1(root,res);
        post_iterative2(root,res);
        return res;
    }
    
private:
    void post_recursive(TreeNode* root, vector<int> &res){
        if(root == NULL) return;
        post_recursive(root->left, res);
        post_recursive(root->right, res);
        res.push_back(root->val);
    }
    
    void post_iterative1(TreeNode* root, vector<int> &res){
        stack<TreeNode*> s;
        TreeNode* curr;
        unordered_set<TreeNode*> visited; // not necessary
        s.push(root);
        while(s.empty() == false){
            curr = s.top();  
            visited.insert(curr);
            if(curr->left && visited.find(curr->left) == visited.end()) {
                s.push(curr->left);
                continue;
            } 
            if(curr->right && visited.find(curr->right) == visited.end()) {
                s.push(curr->right);
                continue;
            }
            res.push_back(curr->val);
            s.pop();
        }
    }
    
    void post_iterative2(TreeNode* root, vector<int> &res){
        stack<TreeNode*> s;
        TreeNode* curr;
        TreeNode* last = NULL;
        s.push(root);
        while(s.empty() == false) {
            curr = s.top();  
            if(curr->left && (!last || last->left == curr || last->right == curr)) {
                last = curr;
                s.push(curr->left);
                continue;
            } 
            if(curr->right && curr->right!= last) {
                last = curr;
                s.push(curr->right);
                continue;
            }
            res.push_back(curr->val);
            last = curr;
            s.pop();
        }
    }  
};
