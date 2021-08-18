#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define pb push_back
#define v vector
#define f first
#define s second

struct Graph{
    ll value;
    v <ll> adj_list;
};

v<Graph> dfsCC(v<Graph> G,v<ll> &visited,ll ind){
    v<Graph> ans,temp;
    if(G[ind].value==ind)
        ans.pb(G[ind]);
    visited[ind]=1;
    for(auto i=G[ind].adj_list.begin();i!=G[ind].adj_list.end();i++){
        if(!visited[*i]){
            temp=(dfsCC(G,visited,*i));
            ans.insert(ans.end(),temp.begin(),temp.end());
        }
    }    
    return ans;
}

ll connectedComp(vector<Graph> G){
    ll n=G.size(),count=-1;
    v<v<Graph>> connectedCompVectors;
    v<ll> visited(n,0);
    for(ll i=0;i<n;i++){
        // cout<<i<<endl;
        if(!visited[i]){
           connectedCompVectors.pb( dfsCC(G,visited,i));
        }
    }
    for(v<v<Graph>>::iterator i=connectedCompVectors.begin();i!=connectedCompVectors.end();i++){
        v<Graph> ::iterator j =i->begin();
        for(;j!=(*i).end();j++){
            cout<<(*j).value<<" ";
        }
        cout<<endl;
    }
    return 1;
}





int main(){
    ll N=10;
    vector<Graph> G(N);
    for(ll i=0;i<5;i++){
        ll t1,t2;
        cin>>t1>>t2;
        G[t1].value=t1;
        G[t1].adj_list.pb(t2);
        G[t2].value=t2;
        G[t2].adj_list.pb(t1);
    }
    connectedComp(G);

    return 0;
}