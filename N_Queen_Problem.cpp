#include<iostream>
using namespace std;
#include <bits/stdc++.h>

void addToAnswer(vector<vector<int>> board,vector<vector<int>>ans,int n){

    vector<int> temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp.push_back(board[i][j]);
        }
    } 
    ans.push_back(temp);
}

bool isSafe(int row,int column,vector<vector<int>> board,int n){

    int x=row;
    int y=column;
    //check for row
    while(y>0){
        if(board[row][column]==1){
            return false;
        }
        y--;
    }
    y=column;

    //diagonal
    while(x>0&&y>0){
        if(board[x][y]==1){
            return false;
        }
        x--;
        y--;
    }
    while(x<n&&y>0){
        if(board[x][y]==1){
            return false;
        }
        x++;
        y--;
    }

    return true;

}

void solve(int column,vector<vector<int>> board,vector<vector<int>>ans,int n){

    //base case
    if(column==n){
        addToAnswer(board,ans,n);
    }

    for(int row=0;row<n;row++){
        if(isSafe(row,column,board,n)){

            board[row][column]=1;
            solve(column+1,board,ans,n);
            board[row][column]=0;

        }
    }
}
vector<vector<int>> nQueen(int n){

    vector<vector<int>> board;
    vector<vector<int>>ans;

    solve(0,board,ans,n);

    return ans;


}
