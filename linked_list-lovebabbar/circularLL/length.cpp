#include<iostream>
using namespace std;
class Node{
    public:
    Node* prev;
    int data;
    Node* next;
    Node(int value){
        this->data = value;
        this->next = nullptr;
        this->prev = nullptr;
    }
    
};
int length(Node* &head){
    Node* temp=head;
    int length=0;
    while(temp!=nullptr){
        temp=temp->next;
        length++;
    }
    return length;
}
void print(Node* &head){
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"null"<<endl;
}
Node* insertAtHead(int value,Node* &head,Node* &tail){
    if(head==nullptr && tail==nullptr)
    {
        Node* newNode=new Node(value);
        head=newNode;
        tail=newNode;
       

    }
    else{
        Node* newNode = new Node(value);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        
    }
    return head;

}

int main(){
    Node* head=nullptr;
    Node* tail=nullptr;
    insertAtHead(10,head,tail);
    insertAtHead(20,head,tail);
    insertAtHead(30,head,tail);
    insertAtHead(40,head,tail);
    print(head);
    cout<<length(head)<<endl;
    return 0;
}