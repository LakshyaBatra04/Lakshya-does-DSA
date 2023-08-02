#include<iostream>
using namespace std;
#include <queue>

class node{
    public :
        int data;
        node* left;
        node* right;

    //constructor
    node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
node* buildTree(node *root){
    cout<<"Enter data"<<endl;
    int data;
    cin>>data;
    root=new node(data);

    if(data==-1){
        return NULL;
    }
    cout<<" to insert in left of"<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"  to insert in right of"<<data<<endl;
    root->right=buildTree(root->right);
    return root;
}

void levelOrderTraversal(node*root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        node*temp=q.front();

        q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";

            if(temp->left!=NULL){
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
            }
        }
        
    }
}
int main(){
    node*root=NULL;
    root=buildTree(root);
    levelOrderTraversal(root);
}