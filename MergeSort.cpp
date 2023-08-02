#include<iostream>
using namespace std;
#include<vector>
#include<stack>

void merge(int *arr,int left, int right){
    int mid=left+(right-left)/2;
    int len1=mid-left+1;
    int len2=right-mid;

    int*subArray1=new int[len1];
    int*subArray2=new int[len2];

    int mainIndex=left;
    int index1=0;
    int index2=0;

    for(int i=0;i<len1;i++){
        subArray1[i]=arr[i+left];
    }
    for(int i=0;i<len2;i++){
        subArray2[i]=arr[mid+i+1];
    }
    while(index1<len1&&index2<len2){
        if(subArray1[index1]>=subArray2[index2]){
            arr[mainIndex]=subArray2[index2];
            index2++;
        }
        else{
            arr[mainIndex]=subArray1[index1];
            index1++;
        }
        mainIndex++;
    }
    while(index1<len1){
        arr[mainIndex++]=subArray1[index1++];
    }
    while(index2<len2){
        arr[mainIndex++]=subArray1[index2++];
    }
    delete subArray1;
    delete subArray2;

}
void mergeSort(int *arr,int s, int e){
    int mid=s+(e-s)/2;
    if(s>=e){
        return ;
    }
    else{
        mergeSort(arr,s,mid);
        mergeSort(arr,mid+1,e);
        merge(arr,s,e);
    }
}