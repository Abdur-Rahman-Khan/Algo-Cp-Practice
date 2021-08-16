#include<bits/stdc++.h>
using namespace std;
struct Graph{
    vector<int> link;
};
vector <struct Graph> head;
vector <int> visited,reached;
void dfsCall(int start,int num){
    int i,j,temp;
    visited[start]=num;
    printf("->%d %d",start,num);
    for(i=0;i<head[start].link.size();i++){
        if(!visited[head[start].link[i]]){
            //visited[head[start].link[i]]=1;
            dfsCall(head[start].link[i],num+1);
        }
    }
}
void dfs(int start){
    int i;
    fill(visited.begin(), visited.end(), 0);
    fill(reached.begin(), reached.end(), 0);
    dfsCall(start,1);
    for(i=0;i<head.size();i++){
        if(!visited[i]){
            //NewLine
            cout<<endl;
            dfsCall(i,1);
        }
    }
}
void addEdge(int i,int j){
    head[i].link.push_back(j);
}
void input(){
    int i,n,j,temp,m;
    cin>>n;
    head.resize(n);
    visited.resize(n);
    reached.resize(n);
    // for(i=0;i<n;i++){
    //     cin>>temp;
    //     for(j=0;j<temp;j++){
    //         cin>>m;
    //         head[i].link.push_back(m);
    //     }
    // }
    // cin>>n;
    // cin>>m;
    // addEdge(n,m);
    cin>>temp;
    for(i=0;i<temp;i++){
        cin>>n>>m;
        addEdge(n,m);
        addEdge(m,n);   //For undirectedEdge or Two way Edge
    }
}
int main(){
    input();
    dfs(0);
    return 0;
}