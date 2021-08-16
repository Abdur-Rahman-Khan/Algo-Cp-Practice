#include<bits/stdc++.h>
using namespace std;
struct Graph{
    vector<int> link;
    vector<int> weight;
};
vector <struct Graph> head;
vector <int> visit;
list <int> bf,bfw;

void addEdge(int i,int j,int w){
    head[i].link.push_back(j);
    head[i].weight.push_back(w);
}
void input(){
    int i,n,j,temp,m,w;
    cin>>n;
    head.resize(n);
    visit.resize(n);
    fill(visit.begin(),visit.end(),999);
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
void findPathInsert(int s,int t,int w){
    if(s==t){
        //Answer Here is printed Can be stored in GLobal variable
        cout<<w<<endl;
        return;
    }
    for(int i=0;i<head[s].link.size();i++){
        bf.push_front(head[s].link[i]);
        bfw.push_front(w+head[s].weight[i]);
    }
}
void findPath(int s,int t,int w){
    int i,j,k,count=0,min=999;
    // for(int i=0;i<head[s].link.size();i++){
    //     bf.push_back(head[s].link[i]);
    //     bfw.push_back(w+head[s].weight[i]);
    // }
    findPathInsert(s,t,w);
    while(!bf.empty()){
        if(visit[bf.back()]>=bfw.back()){
            visit[bf.back()]=bfw.back();
            findPathInsert(bf.back(),t,bfw.back());
        }
        bf.pop_back();
        bfw.pop_back();
    }
   // return 1;
    // if(s==t){
    //     cout<<"Found"<<endl;
    //     return 0;
    // }
    // if(visit[s]!=0)
    //     return visit[s];
    // for(int i=0;i<head[s].link.size();i++){
    //     count=head[s].weight[i]+findPath(head[s].link[i],t);
    //     if(min>count){
    //         min=count;
    //     }
    // }
    //     visit[s]=999;
    // return min;
}
void branchAndBound(){
    int s,t;
    cout<<"Enter s t\n";
    cin>>s>>t;
    findPath(s,t,0);
    // cout<<findPath(s,t,0)<<endl;
}
int main(){
    input();
    branchAndBound();
    return 0;
}