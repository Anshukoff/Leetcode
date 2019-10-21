#include <iostream>
//#include <cmath>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	int findTilt(TreeNode* root);
	int tiltDFS(TreeNode* root, int& tilt);
};

int Solution::findTilt(TreeNode* root) {
	if (!root) {
		return 0;
	}
	else {
		int tiltLeft = 0;
		int tiltRight = 0;
		int sumLeft = 0;
		int sumRight = 0;
		sumLeft = tiltDFS(root->left, tiltLeft);
		sumRight = tiltDFS(root->right, tiltRight);
		return(abs(sumLeft - sumRight) + tiltLeft + tiltRight);
	}
};

int Solution::tiltDFS(TreeNode* root, int& tilt) {
	if (!root) {
		return 0;
	}
	else {
		int leftSum = tiltDFS(root->left, tilt);
		int rightSum = tiltDFS(root->right, tilt);
		tilt += abs(leftSum - rightSum);
		return (leftSum + rightSum + root->val);
	}
};

int main(void) {
	Solution solution;
	TreeNode tree(1);
	tree.left = new TreeNode(2);
	tree.right = new TreeNode(3);
	std::cout << solution.findTilt(&tree) << std::endl;
	int i = getchar();
	return 1;
}