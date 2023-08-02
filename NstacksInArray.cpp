#include<iostream>
using namespace std;
#include<vector>
#include<stack>

class Nstack{
    private:
        int *arr;
        int *top;
        int *next;
        int n;
        int s;
        int freespot;
    public:
        Nstack(int N, int S){
            n=N;
            s=S;
            arr=new int[n];
            top=new int[s];
            next=new int[n];

            //initialize top
            for(int i=0;i<s;i++){
                top[i]=-1;
            }
            //initialize next
            for(int i=0;i<n;i++){
                next[i]=i+1;
            }
            //element at last indexof next is -1
            next[s-1]=-1;

            freespot=0;
    }
        bool push(int data,int Snum){
            //find khaali index
            int index=freespot;
            //update freespot
            freespot=next[index];
            //add the element in the index of array
            arr[index]=data;
            //update next[index] as arr[index] now has data in it
            next[index]=top[Snum-1];
            //update top
            top[Snum-1]=index;

            return true;
        }
};