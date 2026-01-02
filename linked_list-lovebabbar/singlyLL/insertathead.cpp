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
bool search(Node* head,int key){
    Node* temp=head;
    while(temp!=nullptr){
        if(temp->data==key){
            return true;
        }
        temp=temp->next;
    }
    return false;
}
Node* insertAthead(int value,Node* head,Node* tail){
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
void print(Node* head){
    Node* temp=head;
    while(temp!=nullptr){
       
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"Null"<<endl;
};
int main(){
    //stack creation
    // Node* first;
    //dynamic creation
    // Node* first=new Node();
   Node* head=nullptr;
   Node* tail=nullptr;
//    head=insertAthead(10,head,tail);
//    cout<<head->data<<"->";
//    head=insertAthead(20,head,tail);
//    cout<<head->data<<"->";
//    head=insertAthead(30,head,tail);
//    cout<<head->data<<endl;

    head=insertAthead(10,head,tail);
    print(head);
    head=insertAthead(20,head,tail);
    print(head);
    search(head,20)?cout<<"Found":cout<<"Not Found"<<endl;
    return 0;
}