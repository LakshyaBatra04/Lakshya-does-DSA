#include<iostream>
using namespace std;
#include <bits/stdc++.h>

bool isSafe(int val, vector<vector<int>>grid,int row,int col){

    //row check
    int x=row;
    int y=col;

    for(int v=0;v<col;v++){
        if(grid[v][col]==val){
            return false;
        }
    }
    for(int v=0;v<col;v++){
        if(grid[row][v]==val){
            return false;
        }
    }

    //sub Grid check
    for(int i=1;i<=8;i++){
        if(grid[3*(row/3)+i/3][3*(col/3)+i%3]==val){
            return false;
        }
    }

    return false;
}
bool solve(vector<vector<int>>& grid,vector<vector<int>>ans){

    //check for blank space i.e entries with 0
    for(int row=0;row<grid[0].size();row++){
        for(int col=0;col<grid[0].size();col++){
            if(grid[row][col]==0){
                
                for(int val=0;val<9;val++){
                    if(isSafe(val,grid,row,col)){
                        grid[row][col]=val;
                        bool interateNext=solve(grid,ans);
                        if(interateNext){
                            return true;
                        }
                        else{
                            //backtrack
                            grid[row][col]=0;
                        }
                    }
                }
                return false;
            }
        }
        return true;
    }
}

vector<vector<int>>sukoduSolver(vector<vector<int>> grid){

    vector<vector<int>>ans;
    solve(grid,ans);
    return grid;

}