#include<bits/stdc++.h>
using namespace std;
struct Graph{
    vector<int> link;
    vector<int> weight;
};
vector <struct Graph> head;
vector <int> visit;

void addEdge(int i,int j,int w){
    head[i].link.push_back(j);
    head[i].weight.push_back(w);
}
void input(){
    int i,n,j,temp,m,w;
    cin>>n;
    head.resize(n);
    visit.resize(n);
    fill(visit.begin(),visit.end(),0);
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
        cin>>n>>m>>w;
        addEdge(n,m,w);
    //    addEdge(m,n);   //For undirectedEdge or Two way Edge
    }
}
int findPath(int s,int t){
    int i,j,k,count=0,min=999;
    if(s==t){
        cout<<"Found"<<endl;
        return 0;
    }
    if(visit[s]!=0)
        return visit[s];
    for(int i=0;i<head[s].link.size();i++){
        count=head[s].weight[i]+findPath(head[s].link[i],t);
        if(min>count){
            min=count;
        }
    }
        visit[s]=999;
    return min;
}
void branchAndBound(){
    int s,t;
    cout<<"Enter s t\n";
    cin>>s>>t;
    cout<<findPath(s,t)<<endl;
}
int main(){
    input();
    branchAndBound();
    return 0;
}