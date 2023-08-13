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
//to find a balanced binary tree
//a tree is balanced if the diffrence between left and right part is less 
//than or equal to 1 for each node

bool isBalanced(node*root){
    //base call->a NULL tree is always balanced
    if(root==NULL){
        return true;
    }
    //recursive call to left subtree
    bool isLeftBalanced=isBalanced(root->left);
    bool isRightBalanced=isBalanced(root->right);
    int diff=abs(height(root->left)-height(root->right));

    if(isLeftBalanced==true&&isRightBalanced==true&&diff<=1){
        return true;
    }
    return false;
}
//for O(n) time complexity
pair<bool,int> isBalancedFast(node*root){
    //base case
    if(root==NULL){
        pair<bool,int> p=make_pair(true,0);
    }
    //check left part and right part is balanced 
    pair<bool,int>left=isBalancedFast(root->left);
    pair<bool,int>right=isBalancedFast(root->right);
    //check if current node is balanced
    bool currBalanced=abs(left.second-right.second)<=1;
    pair<bool,int> ans;
    if(left.first&&right.first&&currBalanced){
        ans.first=true;
        ans.second=max(left.second,right.second)+1;
    }
    else{
        ans.first=false;
    }
    return ans;
}

/*A code to find SumTree
A sumTree is a tree where at every given node the node data is sum of left
part and right part except the leaf node
OPTIMISED APPROACH WITH O(n) T.C.
*/
pair<bool,int> isSumTreeFast(node*root){

    //base case 1__null node
    if(root==NULL){
        pair<bool,int> p=make_pair(true,0);
        return p;
    }
    //base case 2__leaf node
    if(root->left==NULL&&root->right==NULL){
        pair<bool,int> p=make_pair(true,root->data);
        return p;
    }

    //check if left part is a sumTRee
    pair<bool,int> left=isSumTreeFast(root->left);
    pair<bool,int> right=isSumTreeFast(root->right);

    bool isCurrSumTree=root->data==left.second+right.second;
    //if all threee conditions are true then the subtree is sumtree
    pair<bool,int>ans;
    if(left.first&&right.first&&isCurrSumTree){
        ans.first=true;
        ans.second=root->data+left.second+right.second;
    }
    else{
        ans.first=false;
    }
    return ans;
}
bool isSumTree(node*root){
    pair<bool,int>ans=isSumTreeFast(root);
    return ans.first;
}
//TO find if two tree are identical or not

bool isIndetical(node*root1,node*root2){
    //edge cases
    if(root1==NULL &&root2==NULL){
        return true;
    }
    if(root1==NULL&&root2!=NULL){
        return false;
    }
    if(root1!=NULL&&root2==NULL){
        return false;
    }

    //check left vala subtree
    bool isLeftIdentical=isIndetical(root1->left,root2->left);
    bool isRightIndetical=isIndetical(root1->right,root2->right);
    
    //check data at current position
    bool currIdentical=root1->data==root2->data;

    if(isLeftIdentical&&isRightIndetical&&currIdentical){
        return true;
    }
    return false;
}
//Zig Zag traversal
// T.C. O(n) S.C. O(n);

vector<int> zigZagTraversal(node*root){
    vector<int>result;
    if(root==NULL){
        return result;
    }
//initialize a queue which will contain elements of ith level on ith iteration
    queue<node*>q;
    //root node daaldo
    q.push(root);
    bool leftToRight=true;
    while(!q.empty()){
        //temperory array initalize for each level
        int size=q.size();
        vector<int> ans(size);

        
    //push elements of that level in the array in LtoR/RtoL 
        for(int i=0;i<size;i++){
            int index;
            node*frontNode=q.front();
            q.pop();
            if(leftToRight==true){
                index=i;
                ans[index]=frontNode->data;
            }
            else{
                index=size-i-1;
                ans[index]=frontNode->data;
            }
            if(frontNode->left){
                q.push(frontNode->left);
            }
            if(frontNode->right){
                q.push(frontNode->right);
            }
        }
        leftToRight=!leftToRight;
        for(auto i:ans){
            result.push_back(i);
        }
    }
    return result;
}