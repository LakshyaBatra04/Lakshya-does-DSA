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
void inorderTraversal(node*root){
    if(root==NULL){
        return ;
    }
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}
void preorderTraversal(node*root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void postorderTraversal(node*root){
    if(root==NULL){
        return ;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->data<<" ";
}
void buildfromLvlorder(node*&root){
    queue<node*>q;
    cout<<"Enter data for root:"<<endl;
    int data;
    cin>>data;
    root=new node(data);
    q.push(root);
    while(!q.empty()){
        node*temp=q.front();
        q.pop();
        cout<<"Enter data for left of"<<temp<<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata!=-1){
            temp->left=new node(-1);
            q.push(temp->left);
        }
        cout<<"Enter data for left of"<<temp<<endl;
        int rightdata;
        cin>>rightdata;
        if(rightdata!=-1){
            temp->right=new node(-1);
            q.push(temp->right);
        }
    }

}
int main(){
    node*root=NULL;
    root=buildTree(root);
    levelOrderTraversal(root);
}
