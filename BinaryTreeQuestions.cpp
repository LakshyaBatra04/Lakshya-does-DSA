#include<iostream>
using namespace std;
#include<stack>
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

//code to fing height of binary tree
int height(node*root){
    //base case
    if(root==NULL){
        return 0;
    }
    //left part ki height nikalo
    int left=height(root->left);
    //right part ki height nikalo
    int right=height(root->right);
    //dono ke max mei +1 karke jo aya vo ans
    int ans=max(left,right)+1;
    return ans;
}