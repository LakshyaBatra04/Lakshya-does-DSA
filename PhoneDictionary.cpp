#include<iostream>
using namespace std;
#include<queue>
#include<vector>
#include <bits/stdc++.h>

class trieNode{
    public:
    bool isTerminal;
    char data;
    trieNode* children[26];
    int childCount;

    trieNode(char data){
        this->data=data;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
        childCount=0;
    }
    void insert(char data,trieNode*root){

    }
};
class trie{
    public:
    trieNode*root;
    trie(){
        root=new trieNode('\0');
    }

    void insert(string data,trieNode*root){
        

        if(data.length()==0){
            root->isTerminal=true;
            return;

        }
        char ch=data[0];
        int index=ch-'A';
        trieNode*child;
        if(root->children[index]->data=ch){
            child=root->children[index];
        }
        else{
            trieNode*child=new trieNode(ch);
            root->children[index]=child;
        }
        insert(data.substr(1),child);
    }
    void insertInTrie(string s){
        insert(s,root);
    }
};
void pushWords(vector<string>&temp,trieNode*curr,string prefix){

    if(curr->isTerminal){
        temp.push_back(prefix);
    }

    else{
        for(char ch='A';ch<='Z';ch++){
            trieNode*next=curr->children[ch-'A'];

            if(next!=NULL){
                prefix.push_back(ch);
                pushWords(temp,next,prefix);
                prefix.pop_back();
            }
        }
    }


}
//we are given an array of strings to be inserted in the tree as a data

vector<vector<string>> insertSuggesions(trie*t,string str){
    trieNode*prev=t->root;
    string prefix="";

    vector<vector<string>> output;
    for(int i=0;i<str.size();i++){
        char ch=str[i];
        prefix.push_back(ch);

    //considering all characters as capital letters
        int index=ch-'A';
        trieNode*curr=prev->children[index];
        //if not present , break
        if(prev->children[index]==NULL){
            break;
        }
        else{
            //saare words ko temp mei store kara ke output mei push kardo
            vector<string>temp;
            pushWords(temp,curr,prefix);
            output.push_back(temp);
            temp.clear();
            prev=curr;
        }
    }
    return output;

}
vector<vector<string>> printSuggesions(vector<string>arr,string str){
    trie* t=new trie();
    for(int i=0;i<arr.size();i++){
        t->insertInTrie(arr[i]);
    }
    insertSuggesions(t,str);
}