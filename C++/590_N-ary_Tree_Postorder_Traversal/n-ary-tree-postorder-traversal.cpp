#include <iostream>
#include <vector>

class Node{
public:
    int val;
    std::vector<Node*> children;
    Node(){}
    Node(int _val, std::vector<Node*> _children){
        val = _val;
        children = _children;
    }
};

class Solution{
public:
    std::vector<int> postorder(Node* root);
    void postorderAddition(std::vector<int>& vec, Node* root);
};

void Solution::postorderAddition(std::vector<int>& vec, Node* root){
    if (root){
        for (auto child : root->children){
            postorderAddition(vec, child);
        }
    vec.push_back(root->val);
    }
}

std::vector<int> Solution::postorder(Node* root){
    std::vector<int> result;
    postorderAddition(result, root);
    return result;
}

int main(void){
    Solution solution;
    std::vector<Node*> vec;

    Node* n5 = new Node(5, vec);
    Node* n6 = new Node(6, vec);
    Node* n3 = new Node(3, std::vector<Node*> {n5, n6});
    Node* n2 = new Node(2, vec);
    Node* n4 = new Node(4, vec);
    Node* n1 = new Node(1, std::vector<Node*> {n3, n2, n4});

    std::vector<int> result = solution.postorder(n1);
    for(auto a : result){
        std::cout << a << " ";
    }
    std::cout << std::endl;
    return 0;
}