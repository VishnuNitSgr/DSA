#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

 
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

   
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    void deleteAtBeginning() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

  
    void deleteAtEnd() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next)
            temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }

    
    void deleteAfterValue(int val) {
        Node* temp = head;
        while (temp && temp->data != val)
            temp = temp->next;
        if (temp && temp->next) {
            Node* nodeToDelete = temp->next;
            temp->next = nodeToDelete->next;
            delete nodeToDelete;
        }
    }

    
    bool search(int val) {
        Node* temp = head;
        while (temp) {
            if (temp->data == val)
                return true;
            temp = temp->next;
        }
        return false;
    }

 
    void traverse() {
        Node* temp = head;
        while (temp!=nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};


int main() {
    LinkedList list;

   
    list.insertAtBeginning(5);
    list.insertAtEnd(20);
    list.traverse();   

   

    cout << (list.search(40) ? "Found" : "Not Found") << endl;  
    cout<<list.search(20)<<endl;

    return 0;
}
