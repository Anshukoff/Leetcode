#include <iostream>
#include <queue>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

class Solution{
public:
    TreeNode* invertTree(TreeNode* root);
};

TreeNode* Solution::invertTree(TreeNode* root){
    if (root == nullptr){
        return root;
    }
    std::queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        while(size > 0){
            TreeNode* current = q.front();
            q.pop();
            TreeNode* temp = current->left;
            current->left = current->right;
            current->right = temp;
            if (current->left != nullptr){
                q.push(current->left);
            }
            if (current->right != nullptr){
                q.push(current->right);
            }
            --size;
        }
    }
    return root;
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
    TreeNode tree(4);
    tree.left = new TreeNode(2);
    tree.right = new TreeNode(7);
    tree.left->left = new TreeNode(1);
    tree.left->right = new TreeNode(3);
    tree.right->left = new TreeNode(6);
    tree.right->right = new TreeNode(9);
    Solution solution;
    TreeNode* result = solution.invertTree(&tree);
    std::cout << printTree(result, "") << std::endl;
    return 0;
}
