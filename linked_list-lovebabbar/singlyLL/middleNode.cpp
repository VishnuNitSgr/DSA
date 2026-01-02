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
int length(Node* &head){
    Node* temp=head;
    int len=0;
    while(temp!=nullptr){
        temp=temp->next;
        len++;
    }
    return len;
}
void print(Node* &head){
    Node* temp=head;
    while(temp!=nullptr){
       
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"Null"<<endl;
};
Node* middleNode(Node* &head){
    Node* temp=head;
  
    for(int i=0;i<length(head)/2;i++){
      temp=temp->next;
    }
    Node* middlenode=temp;
    return middlenode;
}
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

int main(){
    Node* head=nullptr;
    Node* tail=nullptr;
    insertAthead(1,head,tail);
    insertAthead(2,head,tail);
    insertAthead(3,head,tail);
    insertAthead(4,head,tail);
    // insertAthead(5,head,tail);
    print(head);
    Node* middle=middleNode(head);
    cout<<middle->data<<endl;
    return 0;
}