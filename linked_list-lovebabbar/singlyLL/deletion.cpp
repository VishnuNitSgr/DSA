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
void print(Node* head){
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
int main(){
return 0;
deleteLL(head,tail,pos);

print(head);

}