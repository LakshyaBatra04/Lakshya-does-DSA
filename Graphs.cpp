#include<iostream>
#include <bits/stdc++.h>
#include <map>
using namespace std;


class graph{
public:
    unordered_map<int,set<int> >adj;

    void addEdge(int u, int v,bool isDirected){

        //isDirected=0 ->undirected graph
        //isDirected=1 ->directed graph

        adj[u].insert(v);

        if(isDirected==0){
            adj[v].insert(u);
        }
    }

    void printAdjList(){

        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<" ,";
            }
            cout<<endl;
        }
    }
    void prepareAdjList(unordered_map<int,set<int>>&adjList,vector<pair<int,int>> &edges){

        int n=edges.size();

        for(int i=0;i<n;i++){

            int u=edges[i].first;
            int v=edges[i].second;

            adjList[u].insert(v);
            adjList[v].insert(u);

        }
        
    }
    void bfs(unordered_map<int,set<int>>&adjList,vector<int>&ans,
            unordered_map<int,bool>&visited, int &node){
        
        queue<int>q;
        q.push(node);
        visited[node]=true;


        while(!q.empty()){
            int frontnode=q.front();
            ans.push_back(frontnode);
            q.pop();

            for(auto i:adjList[frontnode]){
                if(!visited[i]){
                    q.push(i);
                    visited[i]=true;
                }
            }
        }       

        }
    vector<int> BFS(int nodes,vector<pair<int,int>>edges){

        //prepare adjacency list
        unordered_map<int,set<int>>adjList;

        prepareAdjList(adjList,edges);

        vector<int>ans;
        unordered_map<int,bool>visited;
        //to deal with disconnected graphs, call bfs for each node
        for(int i=0;i<nodes;i++){
            if(!visited[i]){
                bfs(adjList,ans,visited,i);
            }
        }
        return ans;
    }
    
};

//TOPOLOGICAL SORT ->Only for directed Acyclic graphs

void topologicalSortDFS(int node,unordered_map<int,set<int>>&adjList,
    unordered_map<int,bool>&visited,stack<int>&s,vector<int>&ans){

        visited[node]=true;

        for(auto i:adjList[node]){
            if(!visited[i]){
                topologicalSortDFS(i,adjList,visited,s,ans);
            }
        }
        s.push(node);
    }

vector<int> topologicalSort(int nodes, vector<pair<int,int>> edges){

    //prepare adjecency list
    unordered_map<int,set<int>>adjList;
    unordered_map<int,bool>visited;
    vector<int>ans;
    stack<int>s;

    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;

        adjList[u].insert(v);
    }

    for(int i=0;i<nodes;i++){
        if(!visited[i]){
            topologicalSortDFS(i,adjList,visited,s,ans);
        }
    }
    while(!s.empty()){
        int top=s.top();
        ans.push_back(top);
        s.pop();
    }
    return ans;
}
// KAHN'S ALGORITHM
//Based on the fact at the nodes with in-degree of 0 @Eachstep should be in the array

vector<int>topoSortKahn(int nodes, vector<pair<int,int>> edges){

    //prepare adjecency list
    unordered_map<int,set<int>>adjList;
    unordered_map<int,bool>visited;
    vector<int>ans;
    stack<int>s;

    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;

        adjList[u].insert(v);
    }

    unordered_map<int,int>indegree;

    for(auto i:adjList){
        for(auto j:i.second){
            indegree[j]++;
        }
    }
    //push all nodes with indegree of 0
    queue<int>q;
    for(int i=0;i<nodes;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int front=q.front();
        ans.push_back(front);
        q.pop();
        for(auto i:adjList[front]){
            indegree[i]--;
            if(indegree[i]==0){
                q.push(i);
            }
        }
    }
}
//Shortest distance in directed graph

//Step 1 -> Prepare Ajacency list for weighted Directed graph
//Step 2 -> Perform Tpological Sort using DFS
//Step 3 -> Initialize array storing distance
//Step 4 -> Modifiy the array accordingly

void dfsTopo(int node,unordered_map<int,bool>&visited,
        unordered_map<int,set<pair<int,int>>>&adj,stack<int>&s){

    visited[node]=true;

    for(auto neighbour:adj[node]){
        if(!visited[neighbour.first]){
            dfsTopo(neighbour.first,visited,adj,s);
        }
        s.push(node);
    }
}
vector<int>shortestDistance(int nodes,int src,int des,
        vector<pair<int,pair<int,int>>>edges){

    //prepare adj list
    unordered_map<int,set<pair<int,int>>>adj;

    for(int i=0;i<edges.size();i++){

        int u=edges[i].second.first;
        int w=edges[i].second.second;
        adj[i].insert(make_pair(u,w));

    }
    stack<int>s;
    unordered_map<int,bool>visited;
    //Perform Tpological sort
    for(int i=0;i<nodes;i++){
        if(!visited[i]){
            dfsTopo(i,visited,adj,s);
        }
    }
    //stack is fucking ready
    vector<int>distanceArray(nodes);
    for(int i=0;i<nodes;i++){
        distanceArray[i]=INT_MAX;
    }
    distanceArray[src]=0;
    
    while(!s.empty()){
        int top=s.top();
        s.pop();
        if(distanceArray[top]!=INT_MAX){
            for(auto neighbour:adj[top]){
                if(neighbour.second+distanceArray[top]<distanceArray[neighbour.first]){
                    distanceArray[neighbour.first]=neighbour.second+distanceArray[top];
                }
            }
        }
    }
}
int main(){

    // int n,m;
    // cout<<"Enter the number of nodes : ";;
    // cin>>n;
    // cout<<endl;
    // cout<<"Enter the number of edges :";
    // cin>>m;

    graph g;
    // for(int i=0;i<m;i++){
    //     int u,v;
    //     cin>>u>>v;
    //     g.addEdge(u,v,0);

    // }
    // g.printAdjList();

    vector<pair<int,int> > edges;
    edges.push_back(make_pair(0,1));
    edges.push_back(make_pair(0,2));
    edges.push_back(make_pair(2,1));
    edges.push_back(make_pair(2,4));
    edges.push_back(make_pair(4,3));
    edges.push_back(make_pair(3,1));


    // g.prepareAdjList(g.adj,edges);
    // g.printAdjList();

    vector<int>ans=g.BFS(5,edges);
    for(auto i:ans){
        cout<<i<<" ";
    }
    
}
