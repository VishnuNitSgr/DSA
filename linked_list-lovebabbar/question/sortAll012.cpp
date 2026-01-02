#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        this->data = value;
        this->next = nullptr;
    }
};

// Used when building initial list from values
Node* insertAtTail(int value, Node* &head, Node* &tail) {
    Node* newNode = new Node(value);
    if (head == nullptr && tail == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    return head;
}

// Used in segregate to add existing nodes
void insertAtTail(Node* node, Node* &head, Node* &tail) {
    if (head == nullptr) {
        head = tail = node;
    } else {
        tail->next = node;
        tail = node;
    }
}

Node* segregate(Node* head) {
    Node* zeroHead = nullptr, *zeroTail = nullptr;
    Node* oneHead = nullptr, *oneTail = nullptr;
    Node* twoHead = nullptr, *twoTail = nullptr;

    Node* temp = head;

    while (temp != nullptr) {
        Node* toMove = temp;
        temp = temp->next;
        toMove->next = nullptr;

        if (toMove->data == 0) {
            insertAtTail(toMove, zeroHead, zeroTail);
        } else if (toMove->data == 1) {
            insertAtTail(toMove, oneHead, oneTail);
        } else if (toMove->data == 2) {
            insertAtTail(toMove, twoHead, twoTail);
        }
    }

    // Merge all three lists
    if (zeroHead != nullptr) {
        zeroTail->next = (oneHead != nullptr) ? oneHead : twoHead;
    }
    if (oneHead != nullptr) {
        oneTail->next = twoHead;
    }

    return (zeroHead != nullptr) ? zeroHead : (oneHead != nullptr) ? oneHead : twoHead;
}

// Helper to print the list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    // Sample input: 1 -> 2 -> 0 -> 1 -> 2 -> 0
    insertAtTail(1, head, tail);
    insertAtTail(2, head, tail);
    insertAtTail(0, head, tail);
    insertAtTail(1, head, tail);
    insertAtTail(2, head, tail);
    insertAtTail(0, head, tail);

    cout << "Original List: ";
    printList(head);

    head = segregate(head);

    cout << "Segregated List: ";
    printList(head);

    return 0;
}
