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
Node* insertAtTail(int value,Node* &head,Node* &tail){
    if(head==nullptr&&tail==nullptr){
        Node* newNode=new Node(value);
        head=newNode;
        tail=newNode;
    }
    else{
        Node* newNode=new Node(value);
        tail->next=newNode;
        tail=newNode;


    }
    return head;
}
void print(Node* head){
    Node* temp=head;
    while(temp!=nullptr){
       
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"Null"<<endl;
};
int main(){
    Node* head=nullptr;
    Node* tail=nullptr;
    head=insertAtTail(10,head,tail);
    print(head);
    head=insertAtTail(20,head,tail);
    print(head);
    return 0;
}