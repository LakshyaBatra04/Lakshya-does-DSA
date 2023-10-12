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

//Boundary traversal of Binary tree

void leftTraversal(Node*root, vector<int> &ans){
    if((root==NULL)||(root->left==NULL&&root->right==NULL)){
        return ;
    }
    ans.push_back(root->data);
    if(root->left){
        leftTraversal(root->left,ans);
    }
    else{
        leftTraversal(root->right,ans);
    }
        
    }
    //leaf node store karlo
    void leafTraversal(Node*root,vector<int>& ans){
        //base case
        if(root==NULL){
            return ;
        }
        if(root->left==NULL&&root->right==NULL){
            ans.push_back(root->data);
            return;
        }
        
        leafTraversal(root->left,ans);
        
        leafTraversal(root->right,ans);
        
    }
    //right vale store karado
void rightTraversal(Node*root, vector<int>& ans){
    if((root==NULL)||(root->left==NULL&&root->right==NULL)){
        return ;
    }
    if(root->right){
        rightTraversal(root->right,ans);
    }
    else{
        rightTraversal(root->left,ans);
    }
    //wapas aagye store karlo
    ans.push_back(root->data);
    
}
vector <int> boundary(Node *root)
{    
    vector<int> ans;
    if(root==NULL){
        return ans;
    }
    ans.push_back(root->data);
    
    leftTraversal(root->left,ans);
    
    leafTraversal(root->left,ans);
    leafTraversal(root->right,ans);
    
    rightTraversal(root->right,ans);
    
    return ans;
}
vector<int> verticalOrder(Node *root)
{
    //base casee
    vector<int> ans;
    //we need a queue to store the node, its horizontal distance from root and its level
    queue< pair<Node*, pair<int,int> > > q;
    //we need a map 
    map<int, map<int, vector<int> > > nodes;
    if(root==NULL){
        return ans;
    }
    //q mei root push karo
    q.push(make_pair(root,make_pair(0,0)));
    
    while(!q.empty()){
        pair<Node*, pair<int ,int> > temp=q.front();
        q.pop();
        
        int hd=temp.second.first;
        int lvl=temp.second.second;
        int data=temp.first->data;
        
        //map mei daala
        nodes[hd][lvl].push_back(data);
        if(temp.first->left){
            q.push(make_pair(temp.first->left,make_pair(hd-1,lvl+1)));
        }
        if(temp.first->right){
            q.push(make_pair(temp.first->right,make_pair(hd+1,lvl+1)));
        }
        
    }
    for(auto i:nodes){
        for(auto j:i.second){
            for(auto k:j.second){
                ans.push_back(k);
            }
        }
    }
    return ans;
}  
// To find lowest common ancestor of two nodes

Node* solve(Node*root,int n1, int n2){
//base cases
    if(root==NULL){
        return NULL;
    }
    if(root->data==n1){
        return root;
    }
    if(root->data==n2){
        return root;
    }
    Node*leftAns=solve(root->left,n1,n2);
    Node*rightAns=solve(root->right,n1,n2);

    if(leftAns!=NULL&&rightAns!=NULL){
        return root;
    }
    if(leftAns!=NULL&&rightAns==NULL){
        return leftAns;
    }
    if(leftAns==NULL&&rightAns!=NULL){
        return rightAns;
    }
    if(leftAns==NULL&&rightAns==NULL){
        return NULL;
    }

}
Node* lca(Node* root ,int n1 ,int n2 )
{
    //Your code here 
    return solve(root,n1,n2);
    
}  
void solve(Node*root,int k,int &count,vector<int>s){
    if(root==NULL){
        return;
    }
    s.push_back(root->data);
    
    solve(root->left,k,count,s);
    solve(root->right,k,count,s);
    
    int sum=0;
    for(int i=s.size()-1;i>=0;i--){
        sum=sum+s[i];
        if(sum==k){
            count++;
        }
    }
    s.pop_back();
}
int sumK(Node *root,int k)
{
    // code here 
    vector<int>s;
    int count=0;
    solve(root,k,count,s);
    return count;
}

//construct a binary tree from inorder+ preorder traversal
int findPosition(int n, int arr[],int len){
    for(int i=0;i<n;i++){
        if(arr[i]==n){
            return i;
            break;
        }
    }
    return -1;
}
Node* solve(int in[],int pre[],int index,int inStart, int inEnd, int len){
    //base case
    //agar pre ki index>=n ya instart>inend
    if(index>=len||inStart>inEnd){
        return NULL;
    }
    Node* root=new Node(pre[index]);
    int position=findPosition(pre[index],in,len);
    index++;
    root->left=solve(in,pre,index,0,position-1,len);
    root->left=solve(in,pre,index,position+1,len-1,len);

    return root;
}
Node* constructTree(int in[], int pre[], int n){
    Node*ans=solve(in,pre,0,0,n-1,n);
    return ans;
}

//MORRIS Traversal for inorder  (traversal without using stacks or queues, better S.C)

Node*findPre(Node*curr){
    Node*temp=curr;
    temp=temp->left;
    while(temp->right!=NULL &&temp->right!=curr){
        temp=temp->right;
    }
    return temp;
}
vector<int> morrisTraversal(Node*root){
    vector<int> ans;

    Node*current=root; 
    while(current!=NULL){

        if(current->left!=NULL){
            Node* pre=findPre(current);
            if(pre->right==NULL){
                pre->right=current;
                current=current->left;
            }
            else{
                pre->right=NULL;
                ans.push_back(current->data);
                current=current->right;
            }
           
        }
        else{
            ans.push_back(current->data);
            current=current->right;
        }
    }
    return ans;
}