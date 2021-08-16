#include<bits/stdc++.h>
using namespace std;
struct Graph{
    vector<int> link;
};
vector <struct Graph> head;
vector <int> visited,label,low,ap,parent;
void addEdge(int i,int j){
    head[i].link.push_back(j);
}
void input(){
    int i,n,j,temp,m;
    cin>>n;
    head.resize(n);
   // visited.resize(n);
   // reached.resize(n);
    label.resize(n);
    low.resize(n);
    ap.resize(n);
    parent.resize(n);
    fill(label.begin(),label.end(),-1);
    fill(ap.begin(),ap.end(),-1);
    fill(parent.begin(),parent.end(),-1);
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
void APdfs(int u){
    static int time=0;
    label[u]=time++;
    int child=0;
    low[u]=label[u];
    for(int i=0;i<head[u].link.size();i++){
        int v=head[u].link[i];
        if(label[v]==-1){
            parent[v]=label[u];
            child++;
            APdfs(v);

            low[u]=min(low[u],low[v]);
            //Case1
            // if(parent[u]==-1&&child>1)
            //     cout<<""<<u<<endl;
        
            //Case2
            if(label[u]<low[v]){
                cout<<v<<""<<u<<endl;
            }
           
        }
        else if(parent[u]!=label[v]){
            low[u]=min(low[u],label[v]);
        }
        
    }   
}
void Bridedge(){
    for(int i=0;i<head.size();i++){
        if(label[i]==-1)
            APdfs(i);
    }
}
int main(){
    input();
    Bridedge();
    return 0;
}
