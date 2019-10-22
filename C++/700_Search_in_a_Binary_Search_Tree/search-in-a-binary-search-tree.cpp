#include <iostream>
#include <string>

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};

class Solution{
public:
	TreeNode* searchBST(TreeNode* root, int val);
};

TreeNode* Solution::searchBST(TreeNode* root, int val){
	if(!root){
		return nullptr;
	}
	if(root->val == val){
		return root;
	} else if (root->val >= val){
		root = searchBST(root->left, val);
	} else if (root->val < val) {
		root = searchBST(root->right, val);
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

// tree = [4,2,7,1,3] Value to search = 2
int main(void){
	Solution solution;
	TreeNode tree(4);
	tree.left = new TreeNode(2);
	tree.right = new TreeNode(7);
	tree.left->left = new TreeNode(1);
	tree.left->right = new TreeNode(3);
	TreeNode* resultTree = solution.searchBST(&tree, 2);
	std::cout << printTree(resultTree, "") << std::endl;
	int i = getchar();
	return 0;
}