#include<iostream>
using namespace std;
#include<vector>
#include<stack>

vector<int>nextsmallElement(int *heights,int n){
    stack<int> s;
    s.push(-1);
    vector<int>ans(n);
    for(int i=n-1;i>=0;i--){
        int curr=heights[i];
        while(s.top()!=-1&&heights[s.top()]>=curr)
            {
            s.pop();
            }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}
vector<int>prevsmallElement(int *heights, int n){
    stack<int> s;
    s.push(-1);
    vector<int>ans(n);
    for(int i=0;i<n;i++){
        int curr=heights[i];
        while(s.top()!=-1&&heights[s.top()]>=curr)
            {
            s.pop();
            }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}
int largestrectangularArea(int *heights, int n){
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
int maxAreaInBM(int M[10000][10000],int n, int m){
    //compute the area of FIRST row
    int area=largestrectangularArea(M[0],m);
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(M[i][j]!=0){
                M[i][j]=M[i][j]+M[i-1][j];
            }
            else{
                M[i][j]=0;
            }
        }
        int maxArea=largestrectangularArea(M[i],m);
        area=max(area,largestrectangularArea(M[i],m));
    }
    return area;
}