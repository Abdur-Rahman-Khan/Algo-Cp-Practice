#include<bits/stdc++.h>
using namespace std;
struct Graph{
    vector<int> link;
};

vector <struct Graph> head;
vector <int> visited,distance1;
list <int> list1;
int iteration1;

void bfsCall(int start){
    int i,j;
    printf("->%d %d %d",start,visited[start],distance1[start]);
    for(i=0;i<head[start].link.size();i++){
       if(!visited[head[start].link[i]]){
            list1.push_front(head[start].link[i]);
            distance1[head[start].link[i]]=distance1[start]+1;
            visited[head[start].link[i]]=iteration1;
        }
    }

}
void bfs(int start){
    int i,j;
    iteration1++;
    //newLine
    cout<<endl;
    visited[start]=iteration1;
    distance1[start]=1;
    bfsCall(start);
    while(!list1.empty()){
        j=list1.back();
        list1.pop_back();
        bfsCall(j);
    }
    for(i=0;i<head.size();i++){
        if(!visited[i]){
           // cout<<"here";
            bfs(i);
        }
    }
}
void bfsStart(int start){
    fill(visited.begin(), visited.end(), 0);
    fill(distance1.begin(), distance1.end(), 0);
    iteration1=0;
    bfs(start);
}

void addEdge(int i,int j){
    head[i].link.push_back(j);
}

void input(){
    int i,n,j,temp,m;
    cin>>n;
    head.resize(n);
    visited.resize(n);
    distance1.resize(n);
   

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
        addEdge(m,n);   //For undirectedEdge or Two way Edge
    }
}
int main(){
    input();
    bfsStart(0);
    return 0;
}