#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define pb push_back
#define v vector
#define f first
#define s second
ll findoneLCA(map<ll,v<ll>> &g,ll t1, ll t2,ll i){
    if((i==t1)||i==t2)
        return i;
    ll a=0,b=0;
    if(g[i].size()>0)
        a=findoneLCA(g,t1,t2,g[i][0]);
    if(g[i].size()==2)
        b=findoneLCA(g,t1,t2,g[i][1]);
    if (a and b)
        return i;
    return a>b?a:b;
}
void printancestor(map<ll,v<ll>> &ancestor){
    cout<<"SIZe:"<<ancestor.size()<<endl;
    for(auto i=ancestor.begin();i!=ancestor.end();i++){
        cout<<i->f<<": ";
        for(ll j=0;j<i->s.size();j++){
            cout<<i->s[j]<<" ";
        }
        cout<<endl;
    }
}
void dfsparent(map<ll,v<ll>> &g, map<ll,v<ll>> &ancestor,ll root){
    // cout<<"R"<<root<<endl;
    for(ll i=0;i<g[root].size();i++){
        ancestor[g[root][i]].pb(root);
        dfsparent(g,ancestor,g[root][i]);
    }
    // parent[root]=root;
}
void dfsancestor(map<ll,v<ll>> &g,map<ll,v<ll>> &ancestor,ll root,ll j){
    for(ll i=0;i<g[root].size();i++){
        ancestor[g[root][i]].pb(ancestor[ancestor[g[root][i]][j-1]][j-1]);
        dfsancestor(g,ancestor,g[root][i],j);
    }
}
void LCAbinarypre(map<ll,v<ll>> &g,map<ll,v<ll>> &ancestor,ll root){
    ancestor[root].pb(root);
    dfsparent(g,ancestor,root);
    // printancestor(ancestor);
    // cout<<"LOG: "<<log2(g.size()+1)<<"of:"<<g.size()<<endl;
    for(ll i=1;i<log(g.size())+1;i++){
        ancestor[root].pb(root);
        dfsancestor(g,ancestor,root,i);
    }
}
ll getKthancestor(map<ll,v<ll>> &ancestor,ll root,ll k){
    k;
    for(ll i=5;i>=0;i--){
        if(k>=(1<<i)){
            root=ancestor[root][i];
            k-=(1<<i);
            // cout<<i<<" "<<root<<endl;

        }
        // cout<<root<<" ";
    }
    return root;
}

void input(){
	ll n,root=0;
    cin>>n;
    map<ll,v<ll>> g;
    map<ll,ll> parent;
    map<ll,v<ll>> ancestor;
    // g.resize(n);
    for(ll i=0;i<n-1;i++){
        ll t1,t2;
        cin>>t1>>t2;
        // g[t1]=t1;
        // g[t2].f=t2;
        g[t1].pb(t2);
    }
    cin>>n;
    root=1;
    LCAbinarypre(g,ancestor,root);
    // printancestor(ancestor);

    // for(ll i=0;i<n;i++){
    //     ll t1,t2;
    //     cin>>t1>>t2;
    //     root=10;
    //     cout<<findoneLCA(g,t1,t2,root)<<endl;
    // }
    // cout<<"Getting LCA"<<endl;
    for(ll i=0;i<n;i++){
        ll t1,t2;
        cin>>t1>>t2;
        root=10;
        cout<<getKthancestor(ancestor,t1,t2)<<endl;
    }
    
}

int main(){
	ios::sync_with_stdio(false), cin.tie(nullptr);
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
    ll T=1;
    // cin>>T;
    for(ll i=1;i<=T;i++){
		// cout<<"Case #"<<i<<": ";
		input();
    }
    return 0;
}