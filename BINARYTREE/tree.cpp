#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
 
    Node(int val){
        this->data=val;
        left=nullptr;
        right=nullptr;
    }

    
};
Node* createTree(){
        cout<<"enter the value for the node"<<endl;
        int value;
        cin>>value;
        if(value==-1)return nullptr;
        else{
            Node* newroot=new Node(value);
            newroot->left=createTree();
            newroot->right=createTree();

            return newroot;
        }

    }
    void preOrderTraversal(Node* root){
        if(!root)return ;
        cout<<root->data;
       preOrderTraversal(root->left);
       preOrderTraversal(root->right);
    }
    void inOrderTraversal(Node* root){
        if(!root)return ;
        inOrderTraversal(root->left);
        cout<<root->data<<endl;
        inOrderTraversal(root->right);
    }
    void postOrderTraversal(Node* root){
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout<<root->data<<endl;
    }
    void levelOrderTraversal(Node* root){
        queue<Node*> q;
        q.push(root);
        q.push(nullptr);
        while(!q.empty()){
            Node* front=q.front();
            q.pop();
            if(front==nullptr){
                cout<<endl;

            }
            else{
           
            cout<<front->data<<endl;
            if(front->left!=nullptr)q.push(root->left);
            if(front->right!=nullptr)q.push(front->right);


            }
            

       }
    }
int main(){
    Node* root;
root=createTree();
cout<<"printing root data"<<root->data<<endl;
return 0;
}