#include<iostream>
using namespace std;
#include<queue>
#include<vector>
#include <bits/stdc++.h>

class trienode{
    public:
        char data;
        trienode* children[26];
        bool isTerminal;
        int childCount;
    
    trienode(char data){
        this->data=data;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
        childCount=0;
    }
};

class trie{
    public:
        trienode*root;
    
    trie(){
        root=new trienode('\0');
    }
    void insertInTrie(trienode*root,string word){

        //base case
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }
        //letter already present
        char letter=word[0];
        trienode*child;
        int index=letter-'A';
        if(root->children[index]!=NULL){
            
            child=root->children[index];
        }
        else{
            child=new trienode(letter);
            root->children[index]=child;
            root->childCount++;

        }
        //recursion
        insertInTrie(child,word.substr(1));
    }
    void insert(string word){
        insertInTrie(root,word);
        return;
    }

    bool searchInTrie(trienode*root, string word){
        int index=word[0]-'A';
        if(word.length()==0){
            if(root->isTerminal==true){
                return true;
            }
            return false;         
        }
    //letter present
        trienode*child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            return false;
        }
        searchInTrie(child,word.substr(1));
    }
    bool search(string word){
        return searchInTrie(root,word);
    }
    void remove(trienode*root,string word){
        int index=word[0]-'A';
        if(word.length()==0){
            if(root->isTerminal==true){
                root->isTerminal=false;
            }
                    
        }
    //letter present
        trienode*child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            return ;
        }
        remove(child,word.substr(1));
    }
};

int main(){
    trie *t=new trie();
    t->insert("LAKSHYA");
    cout<<"Present?"<< t->search("LAKSHYA")<<endl;
    return 0;
}



//Longest common prefix using Trie
int max(int n,int m){
    if(n>m)
        return n;
    return m;
}
int childCount(trienode*temp){
    int ans=0;
    for(int i=0;i<26;i++){
        if(temp->children[i]!=NULL){
            ans++;
        }
    }
    return ans;
}
string longestCommonPrefix(vector <string> &arr,int n){
    string ans="";
    trie *t=new trie();
    for(int i=0;i<n;i++){
        string word=arr[i];
        t->insert(word);

    }
    string first=arr[0];
    for(int i=0;i<arr[0].length();i++){
        if(t->root->childCount==1){
            ans.push_back(arr[0][i]);
        }
        else{
            break;
        }
    }
    return ans;
    
    


}
