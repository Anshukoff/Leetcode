#include <iostream>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};

class Solution{
public:
    TreeNode* increasingBST(TreeNode* root);
    TreeNode* makeNewBST(TreeNode* root, TreeNode* newRoot);

};

TreeNode* Solution::increasingBST(TreeNode* root){
    TreeNode* newTree = new TreeNode(0);
    makeNewBST(root, newTree);
    TreeNode* ret = newTree->right;
    delete(newTree);
    return ret;
}

TreeNode* Solution::makeNewBST(TreeNode* root, TreeNode* newRoot){
    if (root == nullptr){
        return newRoot;
    }
    TreeNode* l = makeNewBST(root->left, newRoot);
    l->right = new TreeNode(root->val);
    l = l->right;
    return makeNewBST(root->right, l);
}

std::string preOrderPrint(TreeNode* start, std::string str){
    if (start != nullptr){
        str += std::to_string(start->val) + "-";
        str = preOrderPrint(start->left, str);
        str = preOrderPrint(start->right, str);
    }
    return str;
}

std::string printTree(TreeNode* start, std::string str){
    str = preOrderPrint(start,"");
    if (str.length() != 0){
        str.erase(str.length()-1);
    }
    return str;
}

int main(void){
    TreeNode tree(5);
    tree.left = new TreeNode(3);
    tree.left->left = new TreeNode(2);
    tree.left->right = new TreeNode(4);
    tree.left->left->left = new TreeNode(1);
    tree.right = new TreeNode(6);
    tree.right ->right = new TreeNode(8);
    tree.right->right->left = new TreeNode(7);
    tree.right->right->right = new TreeNode(9);
    Solution solution;
    TreeNode* resultTree = solution.increasingBST(&tree);
    printTree(resultTree, "");
    return 0;
}
