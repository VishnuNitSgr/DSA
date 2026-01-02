#include<iostream>
#include<unordered_map>
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
void print(Node* head){
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"Null"<<endl;
}
Node* removeDuplicates(Node* head){
    unordered_map<int,bool>mp;
    Node* temp=head;
    Node* prev=nullptr;
    while(temp!=nullptr){
        if (mp[temp->data]) {
            prev->next = temp->next;
            Node* toDelete = temp;
            temp = temp->next;           
            toDelete->next = nullptr;
            delete toDelete;
        }
        else{
            mp[temp->data]=true;
            prev=temp;
            temp=temp->next;
        }
    }
    return head;
}
int main(){
Node* head=new Node(1);
Node* second=new Node(2);
Node* third=new Node(3);
Node* fourth=new Node(3);
Node* fifth=new Node(4);
Node* sixth=new Node(4);
Node* seventh=new Node(5);
head->next=second;
second->next=third;
third->next=fourth;
fourth->next=fifth;
fifth->next=sixth;
sixth->next=seventh;
print(head);
head=removeDuplicates(head);
print(head);
return 0;
}