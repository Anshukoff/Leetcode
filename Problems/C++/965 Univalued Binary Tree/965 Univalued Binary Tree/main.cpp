#include <iostream>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
};

class Solution final {
public:
	Solution();
	~Solution();
	bool isUnivalTree(TreeNode* root);
private:
	int* ptr;
	bool search(TreeNode* root);
};

bool Solution::isUnivalTree(TreeNode* root) {
	if (search(root) == true) {
		return true;
	}
	return false;
};

Solution::Solution() {
	ptr = new int[100];
	for (int i = 0; i < 100; ++i) {
		ptr[i] = 0;
	}
}

Solution::~Solution() {
	delete[](ptr);
}

bool Solution::search(TreeNode* root) {
	int counter = 0;
	if (!root) {
		return false;
	}
	ptr[root->val]++;
	search(root->left);
	search(root->right);
	for (int i = 0; i < 100; ++i) {
		if (ptr[i] > 0) {
			++counter;
			if (counter > 1) {
				return false;
			}
		}
	}
	return true;
};

int main(void) {
	Solution solution;
	TreeNode tree(2);
	tree.left = new TreeNode(2);
	tree.right = new TreeNode(2);
	tree.left->left = new TreeNode(5);
	tree.left->right = new TreeNode(2);
	std::cout << solution.isUnivalTree(&tree) << std::endl;
	int x = getchar();
	return 0;
}