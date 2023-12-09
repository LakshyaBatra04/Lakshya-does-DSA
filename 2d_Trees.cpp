#include<iostream>
using namespace std;
#include<vector>
#include<stack>

class Node{
    public:
    pair<int,int>data;
    Node*left;
    Node*right;

    Node(pair<int,int>data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
class kdTrees{
    public:
    Node*root;

};