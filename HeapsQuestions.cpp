#include<iostream>
using namespace std;
#include<queue>
#include<vector>

class Node{
    public:
        int data;
        Node*next;
    
    Node(){
        this->next=NULL;
    }
    Node(int data){
        this->data=data;
        this->next=NULL;
    } 
};
class compare{
    public:
        bool operator()(Node*a,Node*b){
            return a->data>b->data;
        }
};
Node* sortKLL(vector<Node*>givenArr){
    int n=givenArr.size();
    priority_queue <Node*, vector<Node*>, compare > minHeap;

    for(int i=0;i<n;i++){
        minHeap.push(givenArr[i]);
    }
    Node*head=new Node();
    head=NULL;
    Node*tail=new Node();
    tail=NULL;

    while(!minHeap.empty()){

        Node*temp=minHeap.top();
        minHeap.pop();
        if(head==NULL){
            head=temp;
            tail=head;
        }
        else{
            tail->next=temp;
            tail=temp;
        }
        if(temp->next!=NULL){
            minHeap.push(temp->next);
        }
    }
    return head;

}
