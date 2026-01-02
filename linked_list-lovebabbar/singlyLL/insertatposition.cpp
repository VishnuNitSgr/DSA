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
    cout<<"Null"<<endl;
};
void deleteLL(Node* head,Node* tail,int pos){
    //if ll is empty then cannot delete anything
    if(head==nullptr && tail==nullptr)
    cout<<"LL is empty"<<endl;
    else if(head==tail){
        Node* temp=head;
        head=nullptr;
        tail=nullptr;

        delete head;
        
    }
   //agar multiple nodes present ho tb 
   else{
    //agar first postion se delete krna chahte ho tb
    if(pos==1){
        Node* temp=head;
        head=temp->next;
        temp->next=nullptr;
        delete temp;
        

    }
    else {
        Node* prev=head;
        for(int i=0;i<pos-2;i++){
            prev=prev->next;
        }
        Node* curr=prev->next;
        Node* forward=curr->next;
        prev->next=forward;
        curr->next=nullptr;
        delete curr;
    }
   }
}
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
void insertInBetween(int value, Node* &head, Node* &tail , int pos) {
    Node* temp = head;
    for (int i = 0; i < pos - 2; i++) {
        temp = temp->next;
    }
    Node* newNode = new Node(value);
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertAtPosition(int value,Node* &head,Node* &tail,int position){
    if(position==1){
        insertAthead(value,head,tail);
    }
    else if(position==length(head)+1){
        insertAtTail(value,head,tail);
    }
    else{
        //in between kahi krna chahta hu me insert
        insertInBetween(value,head,tail,position);
    }
}
int main(){
    Node* head=nullptr;
    Node* tail=nullptr;
    insertAtPosition(10,head,tail,1);
    print(head);
    insertAtPosition(20,head,tail,2);
    print(head);
    insertAtPosition(30,head,tail,3);
    print(head);
    insertAtPosition(40,head,tail,4);
    print(head);
    deleteLL(head,tail,3);
    print(head);
    deleteLL(head,tail,2);
    print(head);
    return 0;
}