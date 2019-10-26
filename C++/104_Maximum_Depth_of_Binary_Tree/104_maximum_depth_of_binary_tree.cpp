#include <iostream>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

class Solution{
public:
    int maxDepth(TreeNode* root);
};


int Solution::maxDepth(TreeNode* root){
    if (root == nullptr){
        return 0;
    }
    int result_left = 1 + maxDepth(root->left);
    int result_right = 1 + maxDepth(root->right);
    if(result_left > result_right){
        return result_left;
    }
    return result_right;
};

int main(void){
    TreeNode tree(3);
    tree.left = new TreeNode(9);
    tree.right = new TreeNode(20);
    tree.right->left = new TreeNode(15);
    tree.right->right = new TreeNode(7);
    Solution solution;
    std::cout << solution.maxDepth(&tree) << std::endl;
    return 0;
}
