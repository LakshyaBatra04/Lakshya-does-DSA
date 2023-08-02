#include<iostream>
using namespace std;
#include<vector>
#include<stack>
int binarySearch(int arr[], int s,int e,int num){
    while(s<=e){
        int mid=s+(e-s)/2;
        if(arr[mid]==num){
            return mid;
        }
        else if (arr[mid]>num){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return -1;
}

int recursiveBS(int arr[],int s,int e,int key){
    while(s<=e){
        int mid=s+(e-s)/2;
        //base case
        if(arr[mid]==key){
            return mid;
        }   
        if(arr[mid]>key){
            return recursiveBS(arr,s,mid-1,key);
        }
        else{
            return recursiveBS(arr,mid+1,e,key);
        }
    }
    return -1;
}