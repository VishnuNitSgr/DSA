#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Insert into BST
Node* buildBST(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data)
        root->left = buildBST(root->left, val);
    else
        root->right = buildBST(root->right, val);
    return root;
}

// Search in BST
bool searchBST(Node* root, int key) {
    if (!root) return false;
    if (root->data == key) return true;
    if (key < root->data)
        return searchBST(root->left, key);
    else
        return searchBST(root->right, key);
}

// Find minimum value node (used for deletion)
Node* findMin(Node* root) {
    while (root && root->left)
        root = root->left;
    return root;
}

// Delete from BST
Node* deleteNode(Node* root, int key) {
    if (!root) return nullptr;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data){
        root->right = deleteNode(root->right, key);
    } else {
        // Node found
        // Case 1: No child
        if (!root->left && !root->right) {
            delete root;
            return nullptr;
        }
        // Case 2: One child
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: Two children
        Node* successor = findMin(root->right);
        root->data = successor->data;
        root->right = deleteNode(root->right, successor->data);
    }
    return root;
}

// Level Order Traversal
void levelOrderTraversal(Node* root){
    if (!root) return;

    queue<Node*> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty()) {
        Node* front = q.front();
        q.pop();

        if (front == nullptr) {
            cout << endl;
            if (!q.empty()) q.push(nullptr);
        } else {
            cout << front->data << " ";
            if (front->left) q.push(front->left);
            if (front->right) q.push(front->right);
        }
    }
}

// Create Tree from User Input
Node* createTree(){
    cout << "Enter values to insert into BST (-1 to stop): ";
    int val;
    Node* root = nullptr;
    cin >> val;
    while (val != -1) {
        root = buildBST(root, val);
        cin >> val;
    }
    return root;
}

int main() {
    Node* root = createTree();

    cout << "\nLevel Order Traversal of BST:\n";
    levelOrderTraversal(root);

    // Search
    int key;
    cout << "\n\nEnter value to search in BST: ";
    cin >> key;
    if (searchBST(root, key))
        cout << key << " is found in the BST.\n";
    else
        cout << key << " is NOT found in the BST.\n";

    // Delete
    cout << "\nEnter value to delete from BST: ";
    cin >> key;
    root = deleteNode(root, key);
    cout << "\nLevel Order Traversal after deletion:\n";
    levelOrderTraversal(root);

    return 0;
}
