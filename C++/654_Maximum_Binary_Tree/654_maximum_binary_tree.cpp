#include <iostream>
#include <vector>
#include <unordered_map>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};

class Solution{
public:
    TreeNode* constructMaximumBinaryTree(std::vector<int>& nums);
};

TreeNode* Solution::constructMaximumBinaryTree(std::vector<int>& nums){
    if (nums.size() == 0){
        return nullptr;
    }
    std::unordered_map<TreeNode*, TreeNode*> parent;
    TreeNode* current = nullptr;
    TreeNode* root = nullptr;
    for(const auto& item : nums){
        auto now = new TreeNode(item);
        if (root == nullptr || now->val > root->val){
            root = now;
        }
        while(current != nullptr && current->val < item){
            now->left = current;
            current = parent[current];
        }
        if (current != nullptr){
            current->right = now;
            parent[now] = current;
        }
        current = now;
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
    std::vector<int> input = {3, 2, 1, 6, 0, 5};
    Solution solution;
    TreeNode* result = solution.constructMaximumBinaryTree(input);
    std::cout << printTree(result,"") << std::endl;
    return 0;
}
