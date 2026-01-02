#include <iostream>
using namespace std;

class BST {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;
        Node(int val) {
            data = val;
            left = right = nullptr;
        }
    };

    Node* root;

    // Insert helper
    Node* insert(Node* node, int val) {
        if (node == nullptr)
            return new Node(val);
        if (val < node->data)
            node->left = insert(node->left, val);
        else if (val > node->data)
            node->right = insert(node->right, val);
        return node;  // unchanged node pointer
    }

    // Search helper
    bool search(Node* node, int key) {
        if (node == nullptr)
            return false;
        if (key == node->data)
            return true;
        else if (key < node->data)
            return search(node->left, key);
        else
            return search(node->right, key);
    }

    // Find min node (used in delete)
    Node* findMin(Node* node) {
        while (node && node->left != nullptr)
            node = node->left;
        return node;
    }

    // Delete helper
    Node* deleteNode(Node* node, int key) {
        if (node == nullptr) return node;

        if (key < node->data)
            node->left = deleteNode(node->left, key);
        else if (key > node->data)
            node->right = deleteNode(node->right, key);
        else {
            // Node found
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            }
            else if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            } else {
                // Node with two children
                Node* temp = findMin(node->right);
                node->data = temp->data;
                node->right = deleteNode(node->right, temp->data);
            }
        }
        return node;
    }

    // Inorder traversal (for display)
    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

public:
    BST() {
        root = nullptr;
    }

    void insert(int val) {
        root = insert(root, val);
    }

    bool search(int key) {
        return search(root, key);
    }

    void deleteValue(int key) {
        root = deleteNode(root, key);
    }

    void displayInorder() {
        inorder(root);
        cout << "\n";
    }
};

int main() {
    BST tree;

    // Insert values
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Inorder traversal: ";
    tree.displayInorder();  // Should print sorted elements

    // Search
    cout << "Search 60: " << (tree.search(60) ? "Found" : "Not Found") << endl;
    cout << "Search 25: " << (tree.search(25) ? "Found" : "Not Found") << endl;

    // Delete
    tree.deleteValue(70);
    cout << "Inorder after deleting 70: ";
    tree.displayInorder();

    tree.deleteValue(30);
    cout << "Inorder after deleting 30: ";
    tree.displayInorder();

    return 0;
}
