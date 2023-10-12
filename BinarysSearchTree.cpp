#include<iostream>
using namespace std;
#include<stack>
#include <queue>
#include<vector>
#include<map>
 
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
class Node{
    public :
        int data;
        Node* left;
        Node* right;

    //constructor
    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
void levelOrder(Node* root){
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        Node*temp=q.front();
        q.pop();
        if(q.empty()){
            cout<<temp->data;
            cout<<endl;
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

Node* insertInBST(Node*root, int d){
    //node aayi
    if(root==NULL){
        Node* temp=new Node(d);
        root=temp;
        return root;
    }
    else{
        if(d<root->data){
            root->left=insertInBST(root->left,d);
        }
        else{
            root->right=insertInBST(root->right,d);
        }
    }
    return root;
}
//now to build a BST , recursively inset the whole set of data in the BST
void makeBST(){
    Node*root=NULL;
    int d;
    while(d!=-1){
        cin>>d;
        root=insertInBST(root,d);
    }
    //print the root
    levelOrder(root);
}

Node* minVal(Node*root){
    Node*temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}
Node* maxVal(Node*root){
    Node*temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}

Node* deleteNode(Node*root, int d){
    Node*temp=root;
    //case 1 : root ka data is bigger

    if(root->data>d){
        root->left=deleteNode(root->left,d);
    }
    // root ka data is smaller
    else if(root->data<d){
        root->right=deleteNode(root->right,d);
    }
    // pahuch gye
    else{
        //case1 :no child
        if(root->left==NULL){
            Node*temp=root->right;
            delete root;
            return temp;
        }
        if(root->right==NULL){
            Node*temp=root->left;
            delete root;
            return temp;
        }
        else{
            //both child present;
            //find inorder precedetor (smallest element in the right subtree)
            Node*temp=minVal(root->right);
            root->data=temp->data;
            root->right=deleteNode(root->right,temp->data);

        }

    }
    return root;    
}
vector<int> inorder(Node*root){
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    inorder(root->left);
    ans.push_back(root->data);
    inorder(root->right);

}
bool validBST(Node*root){
    vector<int>ans=inorder(root);
    for(int i=0;i<ans.size()-1;i++){
        if(ans[i]>ans[i+1]){
            return false;
        }
    }
    return true; 
}

int kthSmallestInBST(Node*root, int k){
    //using Morris Traversal
    vector<int>ans;
    int i=0;
    if(i==k){
        return ans[i-1]; 
    }
    Node*curr=root;
    while(curr!=NULL){

        if(curr->left!=NULL){
            Node*temp=curr->left;
            while(temp->right!=NULL&&temp->right!=curr){
                temp=temp->right;
            }
            if(temp->right!=curr){
                temp->right=curr;
                curr=curr->left;
            }
            else{
                ans.push_back(curr->data);
                i++;
                curr=curr->right;
                temp->right=NULL;
            }    
        }
        else{
            ans.push_back(curr->data);
            i++;
            curr=curr->right;
        }
        if(i==k){
            return ans[i-1];
            break;
        }
    }
}
