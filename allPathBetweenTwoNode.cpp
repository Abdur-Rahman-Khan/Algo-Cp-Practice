#include<bits/stdc++.h>
using namespace std;
struct Graph{
    vector<int> link;
};

vector <struct Graph> head;
vector <int> headpath;
void addEdge(int i,int j){
    head[i].link.push_back(j);
}

void input(){
    int i,n,j,temp,m;
    cin>>n;
    head.resize(n);
    headpath.resize(n);
    fill(headpath.begin(), headpath.end(), -1);

    // for(i=0;i<n;i++){
    //     cin>>temp;
    //     for(j=0;j<temp;j++){
    //         cin>>m;
    //         head[i].link.push_back(m);
    //     }
    // }
    //  addEdge(n,m);
    cin>>temp;
    for(i=0;i<temp;i++){
        cin>>n>>m;
        addEdge(n,m);
       // addEdge(m,n);   //For undirectedEdge or Two way Edge
    }
}
int pathxy(int x, int y){
    if(x==y)
        return 1;
    int i,temp,count;
    if(headpath[x]!=-1){
        return headpath[x];
    }
   // cout<<x<<" "<<y<<endl;
    headpath[x]=0;
    for(i=0;i<head[x].link.size();i++){
        headpath[x]+=pathxy(head[x].link[i],y);
    }
    return headpath[x];
}

void allPath(){
    int x,y;
    cin>>x>>y;
    cout<<pathxy(x,y)<<endl;
    
}
int main(){
    input();
    allPath();
    return 0;
}