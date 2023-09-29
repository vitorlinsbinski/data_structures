#include <iostream>

using namespace std;

class TreeNode {
private:
    TreeNode* left;
    TreeNode* right;
    int value;

public:
    TreeNode(int num) {
        value = num;
        left = nullptr;
        right = nullptr;
    }

    friend class Tree;
};

class Tree {
private:
    TreeNode* root;

     TreeNode* _insert(TreeNode* node, TreeNode* nodeToInsert) {
        if(node) {
            if(nodeToInsert -> value > node -> value) {
                node -> right = _insert(node -> right, nodeToInsert);
            } else if(nodeToInsert -> value < node -> value) {
                node -> left = _insert(node -> left, nodeToInsert);            }
        }

        return node;

    }

    void _printTree(TreeNode* node) {

        if(node) {
            cout << node -> value;
            cout << " ( ";
            _printTree(node -> left);
            _printTree(node -> right);
            cout << " ) ";

        }
    }

public:
    Tree() {
        root = nullptr;
    }

    void insert(int num) {
        TreeNode* node = new TreeNode(num);

        if(root == nullptr) {
            root = node;
        } else {
            _insert(root, node);
        }
    }

    void printTree() {
        if(root == nullptr) {
            cout << "Tree is empty" << endl;
            return;
        } else {
            cout << root -> value << endl;
            _printTree(root);
        }
    }


};

int main() {
    Tree* myTree = new Tree();

    myTree -> insert(59);
    myTree -> insert(12);
    myTree -> insert(41);

    myTree -> printTree();

    return 0;
}
