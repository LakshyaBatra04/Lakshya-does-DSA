#include<iostream>
using namespace std;
#include<vector>
#include<stack>
#include <queue>
#include<map>

class heap{
    public:
    int arr[100];
    int size;
    heap(){
        arr[0]=-1;
        size=0;
    }
  
    void insert(int data){
        size=size+1;
        int index=size;
        arr[index]=data;
        int parent=size/2;

        while(index>1){
            if(arr[index]<arr[parent]){
                swap(arr[index],arr[size]);
                index=parent;
            }
            else{
                return ;
            }
        }
    }
    void deleteFromHeap(){

        arr[1]=arr[size];
        size--;

        int i=1;
        while(i<size){
            int leftChild=2*i;
            int rightChild=2*i+1;
            
            if(leftChild<size&&arr[leftChild]>arr[i]){
                swap(arr[leftChild],arr[i]);
                i=leftChild;
            }
            if(rightChild<size&&arr[rightChild]>arr[i]){
                swap(arr[rightChild],arr[i]);
                i=rightChild;
            }
            else{
                return ;
            }
        }
    }
    //Heapify Algorithm - code to put a particuar index in the array at its correct position

    void heapify(int arr[], int n, int i){

        int current=i;
        int leftChild=2*i;
        int rightChild=2*i+1;

        if(leftChild<=n&&arr[current]<=arr[leftChild]){
            swap(arr[current],arr[leftChild]);
            current=leftChild;
            heapify(arr,n,current);
        }
        if(rightChild<=n&&arr[current]<=arr[rightChild]){
            swap(arr[current],arr[rightChild]);
            current=rightChild;
            heapify(arr,n,current);
        }
        else{
            return ;
        }
    }
    void heapSort(int arr[],int n){

        //heapify the whole array

        for(int i=n/2;i>0;i++){
            heapify(arr,n,i);
        }

        int size=n;
        while(size>1){
            swap(arr[1],arr[size]);
            size--;
            heapify(arr,n,1);
        }
    }
};
//find kth largest subarray sum using heaps

int kthLargestSum(vector<int>arr,int k){

    priority_queue <int, vector<int>, greater<int> > pq; 

    //k elements heap mei daalo
    for(int i=0;i<arr.size();i++){
        int sum=0;
        for(int j=i;j<arr.size();j++){
            sum+=arr[j];
            if(pq.size()<k){
                pq.push(sum);
            }
            else{
                //sum ko compare karo pq ke top se 
                if(sum>pq.top()){
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
    }
    return pq.top();
}
//merge K sorted arrays
class node{
    public:
        int data;
        int row;
        int col;
    node(int data, int row,int col){
        this->data=data;
        this->row=row;
        this->col=col;
    }
};
class compare{
    public:
        bool operator()(node *a,node*b){
            return a->data>b->data;
        }
};

vector<int> kSortedArrays(vector<vector<int>>&Kheaps,int k){

    priority_queue <node*, vector<node*>, compare > minHeap;

    //insert the first element of each row in the min heap
    for(int i=0;i<k;i++){
        node*temp=new node(Kheaps[i][0],i,0);
        minHeap.push(temp);
    } 
    vector<int>ans;
    while(!minHeap.empty()){
        ans.push_back(minHeap.top()->data);

        node*now=minHeap.top();
        int j=now->col;
        int i=now->row;
        minHeap.pop();

        //if next element exists =>daaaldo

        if(j+1<Kheaps[i].size()){
            node*x=new node(Kheaps[i][j+1],i,j+1);
            minHeap.push(x);
        }        
    }
    return ans;
}

