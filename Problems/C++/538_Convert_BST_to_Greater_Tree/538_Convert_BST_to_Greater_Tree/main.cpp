#include <iostream>
#include <string>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	Solution() :sum(0) {};
	int sum;
	TreeNode* convertBST(TreeNode* root);
	void toGreaterTree(TreeNode* root);
};

TreeNode* Solution::convertBST(TreeNode* root) {
	toGreaterTree(root);
	return root;
};

void Solution::toGreaterTree(TreeNode* root) {
	if (!root) {
		return;
	}
	toGreaterTree(root->right);
	sum += root->val;
	root->val = sum;
	toGreaterTree(root->left);
};

std::string preOrderPrint(TreeNode* start, std::string str) {
	if (start != nullptr) {
		str += std::to_string(start->val) + "-";
		str = preOrderPrint(start->left, str);
		str = preOrderPrint(start->right, str);
	}
	return str;
}

std::string printTree(TreeNode* start, std::string str) {
	str = preOrderPrint(start, "");
	if (str.length() != 0) {
		str.erase(str.length() - 1);
	}
	return str;
}

int main(void) {
	TreeNode tree(5);
	tree.left = new TreeNode(2);
	tree.right = new TreeNode(13);
	tree.right->left = new TreeNode(20);
	tree.right->right = new TreeNode(30);
	Solution solution;
	solution.convertBST(&tree);
	std::cout << printTree(&tree, "") << std::endl;
	int pause = getchar();
	return 0;
}