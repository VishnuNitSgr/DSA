#include <iostream>
using namespace std;

class BinaryTree {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;

        // Node(int val) : data(val), left(nullptr), right(nullptr) {}
        Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
}

    };

    Node* root;

    Node* buildTree() {
        int val;
        cout << "Enter node value (-1 for no node): ";
        cin >> val;

        if (val == -1)
            return nullptr;

        Node* newNode = new Node(val);
        cout << "Enter left child of " << val << endl;
        newNode->left = buildTree();
        cout << "Enter right child of " << val << endl;
        newNode->right = buildTree();

        return newNode;
    }

    void preorder(Node* node) {//nlr
        if (!node) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void inorder(Node* node) { //lnr
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void postorder(Node* node) {//lrn
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

public:
    BinaryTree() : root(nullptr) {}

    void createTree() {
        root = buildTree();
    }

    void preorder() {
        preorder(root);
        cout << "\n";
    }

    void inorder() {
        inorder(root);
        cout << "\n";
    }

    void postorder() {
        postorder(root);
        cout << "\n";
    }
};

int main() {
    BinaryTree tree;

    cout << "Build your binary tree:\n";
    tree.createTree();

    cout << "\nPreorder traversal: ";
    tree.preorder();

    cout << "Inorder traversal: ";
    tree.inorder();

    cout << "Postorder traversal: ";
    tree.postorder();

    return 0;
}
