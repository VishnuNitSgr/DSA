#include <iostream>
#include <vector>
#include <algorithm>
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

// Function to add 1 to the number represented by the linked list
Node* addOne(Node* head) {
    // Step 1: Convert linked list to integer
    Node* temp = head;
    int result = 0;
    while (temp != nullptr) {
        result = result * 10 + temp->data;
        temp = temp->next;
    }

    // Step 2: Add one to the number
    result += 1;

    // Step 3: Convert the result back to a linked list
    if (result == 0) return new Node(0);

    vector<int> digits;
    while (result > 0) {
        digits.push_back(result % 10);
        result /= 10;
    }
    reverse(digits.begin(), digits.end());

    Node* newHead = nullptr;
    Node* newTail = nullptr;
    for (int digit : digits) {
        Node* newNode = new Node(digit);
        if (newHead == nullptr) {
            newHead = newTail = newNode;
        } else {
            newTail->next = newNode;
            newTail = newNode;
        }
    }

    return newHead;
}

// Utility function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Manually create linked list for number: 129 => 1 -> 2 -> 9
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(9);

    cout << "Original List: ";
    printList(head);

    Node* result = addOne(head);

    cout << "List After Adding One: ";
    printList(result);

    return 0;
}
