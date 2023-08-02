#include<iostream>
using namespace std;
#include<vector>
#include<stack>

vector<int>nextsmallElement(vector<int>&arr,int n){
    stack<int> s;
    s.push(-1);
    vector<int>ans(n);
    for(int i=n-1;i>=0;i--){
        int curr=arr[i];
        while(s.top()!=-1&&arr[s.top()]>=curr)
            {
            s.pop();
            }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}
vector<int>prevsmallElement(vector<int>&arr,int n){
    stack<int> s;
    s.push(-1);
    vector<int>ans(n);
    for(int i=0;i<n;i++){
        int curr=arr[i];
        while(s.top()!=-1&&arr[s.top()]>=curr)
            {
            s.pop();
            }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}
int largestrectangularArea(vector<int>&heights){
    int n=heights.size();
    vector<int>next=nextsmallElement(heights,n);
    vector<int>prev=prevsmallElement(heights,n);
    int MaxArea=INT64_MIN;
    for(int i=0;i<n;i++){
        int len=heights[i];
        if(next[i]==-1){
            next[i]=n;
        }
        int bd=next[i];
        int area=len*bd;
        MaxArea=max(MaxArea,area);
    }
    return MaxArea;

}