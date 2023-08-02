#include <iostream>
#include<stack>
#include<vector>
using namespace std;

bool knows(int a , int b, vector<vector<int>> &M, int n){
    if(M[a][b]==1){
        return true;
    }
    return false;
}

int celebrity(vector<vector<int>> &M, int n){
    //push every element in the stack
    stack<int> s;
    for(int i=0;i<n;i++){
        s.push(i);
    }
    //compare the top two elements till stack contains a single element
    while(s.size()>1){
        int a=s.top();
        s.pop();
        int b=s.top();
        s.pop();
        if(knows(a,b,M,n)){
            s.push(b);
        }
        else{
            s.push(a);
        }
    }
    //now the stack contains a single element which is a potential celebrity
    //check if it is a celebrity
    int rowCount=0;
    for(int i=0;i<n;i++){
        if(M[s.top()][i]==0){
            rowCount++;
        }
    }
    if(rowCount!=n){
        return -1;
    }
    int colCount=0;
    for(int i=0;i<n;i++){
        if(M[i][s.top()]==1){
            colCount++;
        }
    }
    if(colCount!=n-1){
        return -1;
    }
    return s.top();

}
