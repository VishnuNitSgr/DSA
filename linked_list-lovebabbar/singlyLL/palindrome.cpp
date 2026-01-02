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

void print(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "Null" << endl;
}

Node* reverse(Node* &prev, Node* &curr) {
    if (curr == nullptr)
        return prev;
    Node* forward = curr->next;
    curr->next = prev;
    prev = curr;
    curr = forward;
    return reverse(prev, curr);
}

bool isPalindrome(Node* &head) {
    if (head == nullptr || head->next == nullptr)
        return true;

    Node* fast = head;
    Node* slow = head;
    Node* midprev = nullptr;

    // Find middle of the list
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        midprev = slow;
        slow = slow->next;
    }

    Node* mid = slow;
    Node* firstlistHead = head;

    // Break the list
    if (midprev != nullptr)
        midprev->next = nullptr;

    // Reverse second half
    Node* prev = nullptr;
    Node* curr = mid;
    Node* secondlistHead = reverse(prev, curr);

    // Compare both halves
    Node* temp1 = firstlistHead;
    Node* temp2 = secondlistHead;
    while (temp1 != nullptr && temp2 != nullptr) {
        if (temp1->data != temp2->data)
            return false;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return true;
}

Node* insertAthead(int value, Node* &head, Node* &tail) {
    Node* newNode = new Node(value);
    if (head == nullptr && tail == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    return head;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    insertAthead(1, head, tail);
    insertAthead(2, head, tail);
    insertAthead(2, head, tail);
    insertAthead(1, head, tail);
    insertAthead(3, head, tail);

    print(head);

    if (isPalindrome(head)) {
        cout << "The list is a palindrome." << endl;
    } else {
        cout << "The list is not a palindrome." << endl;
    }

    return 0;
}
