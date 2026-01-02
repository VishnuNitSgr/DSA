#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int value){
        this->data=value;
        this->next=nullptr;
    }


};
void print(Node* &head){
    Node* temp=head;
    while(temp!=nullptr){
       
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"Null"<<endl;
};
Node* insertAthead(int value,Node* &head,Node* &tail){
    if(head==nullptr&&tail==nullptr){
        Node* newNode=new Node(value);
        head=newNode;
        tail=newNode;
    }
    else{
        Node* newNode=new Node(value);
        newNode->next=head;
        head=newNode;
    }
    return head;
}
Node* reverse(Node* &prev, Node* &curr){
    if(curr==nullptr)
    return prev;
   Node* forward=curr->next;
   curr->next=prev;
   prev=curr;
   curr=forward;
   return reverse(prev,curr);
}
int main(){
    Node* head=nullptr;
    Node* tail=nullptr;
    insertAthead(1,head,tail);
    insertAthead(2,head,tail);
    insertAthead(3,head,tail);
    insertAthead(4,head,tail);
    cout<<"original ll"<<endl;
    print(head);
    Node* prev=nullptr;
    Node* curr=head;
    Node* newhead=reverse(prev,curr);
    cout<<"reversed ll"<<endl;
    print(newhead);
    return 0;
}