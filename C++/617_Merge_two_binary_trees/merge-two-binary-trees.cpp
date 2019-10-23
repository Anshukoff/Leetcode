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
	Solution():str(""){}
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2);
	std::string str;
};

TreeNode* Solution::mergeTrees(TreeNode* t1, TreeNode* t2){
	if(!t1){
		return t2;
	}
	if(!t2){
		return t1;
	}
	if(!t1 && !t2){
		return nullptr;
	}

	TreeNode* t = new TreeNode(0);
	t->val = t1->val + t2->val;
	t->left = mergeTrees(t1->left, t2->left);
	t->right = mergeTrees(t1->right, t2->right);
	return t;

};

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

//t1 = [1, 3, 2, 5], t2 = [2, 1, 3, 4, 7]
int main(void){
	Solution solution;

	TreeNode tree1(1);
	tree1.left = new TreeNode(3);
	tree1.right = new TreeNode(2);
	tree1.left->left = new TreeNode(5);

	TreeNode tree2(2);
	tree2.left = new TreeNode(1);
	tree2.right = new TreeNode(3);
	tree2.left->right = new TreeNode(4);
	tree2.right->right = new TreeNode(7);

	TreeNode* resultTree = solution.mergeTrees(&tree1,&tree2);
	std::cout << printTree(resultTree, "") << std::endl;
	int i = getchar();
	return 0;
}