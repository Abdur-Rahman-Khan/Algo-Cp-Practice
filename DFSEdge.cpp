#include<bits/stdc++.h>
using namespace std;
struct Graph{
    vector<int> link;
};
vector <struct Graph> head;

void addEdge(int i,int j){
    head[i].link.push_back(j);
}
void input(){
    int i,n,j,temp,m;
    cin>>n;
    head.resize(n);
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
    //    addEdge(m,n);   //For undirectedEdge or Two way Edge
    }
}

int main(){
    input();
    return 0;
}