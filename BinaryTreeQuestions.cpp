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
//to obtain diameter of A GIVEN binary tree
//approach 1
//BAD solution due to TC of N*N 
int diameter(node*root){
    //base case
    if(root==NULL){
        return 0;
    }
    int opt1=diameter(root->left);
    int opt2=diameter(root->right);
    int opt3=height(root->left)+height(root->right)+1;
    return max(max(opt1,opt2),opt3);
}
pair<int,int> diameterFast(node*root){
    //base call
    if(root==NULL){
        pair<int,int> p=make_pair(0,0);
        return p;
    }
    pair<int,int> left=diameterFast(root->left);
    pair<int,int> right=diameterFast(root->right);
    
    int op1=left.first;
    int op2=right.first;
    int op3=left.second+right.second+1;

    pair<int,int>ans;
    ans.first=max(max(op1,op2),op3);
    ans.second=max(left.second,right.second)+1;
    return ans;
}
