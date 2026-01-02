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
// bool hasCycle(Node* head){
//     unordered_map<Node*, bool>mp;
//     Node* temp=head;
//     while(temp!=nullptr){
//         if(mp[temp]==true)
//         {
//             return true;
//         }
//         else{
//             mp[temp]=true;
//             temp=temp->next;
//         }
//     }
//     return false;
// }

bool tortoiseHasCycle(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=nullptr){
        fast=fast->next;
        if(fast!=nullptr){
            fast=fast->next;
            slow=slow->next;
            if(slow==fast)return true;
        }
    }
    return false;
}
int  main(){
    Node* head=new Node(1);
    Node* second=new Node(2);
    Node* third=new Node(3);
    Node* fourth=new Node(4);
    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=second;
    if(tortoiseHasCycle(head))cout<<"yes cycle is present"<<endl;
    else cout<<"no cycle present"<<endl;
    return 0;
}