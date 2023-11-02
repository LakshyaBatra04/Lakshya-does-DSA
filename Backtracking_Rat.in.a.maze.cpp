#include<iostream>
using namespace std;
#include <bits/stdc++.h>

//given an array of n*n, having blocks where rat can go as 1,and 0 else,
//we should give all paths from which rat can go to (n-1,n-1) in dextological order

bool isSafe(int x,int y,int n,vector<vector<int>>&arr,
    vector<vector<bool>>& isVisited){

    if((x>=0&&x<n)&&(y>=0&&y<n)&&(isVisited[x][y]==false)&&(arr[x][y]==1)){
        return true;
    }
    return false;
}
void solve(int x,int y,vector<vector<int>>&arr,
    vector<vector<bool>>& isVisited,vector<string>&ans
    ,string path,int n){

    if(x==n-1&&y==n-1){
        ans.push_back(path);
        return;
    }
    //4 conditions for D,L,R,U

    //check if down jana allowed hai
    if(isSafe(x+1,y,n,arr,isVisited)){
        isVisited[x][y]=true;
        solve(x+1,y,arr,isVisited,ans,path+"D",n);
        isVisited[x][y]=false;
    }
        //check if left jana allowed hai
    if(isSafe(x,y-1,n,arr,isVisited)){
        isVisited[x][y]=true;
        solve(x,y-1,arr,isVisited,ans,path+"L",n);
        isVisited[x][y]=false;
    }
        //check if RIGHT jana allowed hai
    if(isSafe(x,y+1,n,arr,isVisited)){
        isVisited[x][y]=true;
        solve(x,y+1,arr,isVisited,ans,path+"R",n);
        isVisited[x][y]=false;
    }
        //check if up jana allowed hai
    if(isSafe(x-1,y,n,arr,isVisited)){
        isVisited[x][y]=true;
        solve(x+1,y,arr,isVisited,ans,path+"U",n);
        isVisited[x][y]=false;
    }

}
vector<string> givePaths(vector<vector<int>>arr,int n){

    //initalise the visited path with all marked as not visited (0)

    vector<vector<bool>> isVisited(n,vector<bool>(n,0));
    vector<string>ans;

    string path="";
    //edge case
    if(arr[0][0]==0){
        return ans;
    }
    solve(0,0,arr,isVisited,ans,path,n);
    return ans;
}