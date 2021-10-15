#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define pb push_back
#define v vector
#define F first
#define S second
#define Sort(a) sort(a.begin(),a.end()) 
class unionFind{
    public:
        //First denote link, next size
        // vector<pair<ll,ll>> linkSize;
        vector<ll> Link;
        vector<ll> Size;
        //Constructor
        unionFind(ll n){
            Link.resize(n);
            Size.resize(n);
            for (ll i = 0; i < n; i++) {
                Link[i] = i; Size[i] = 1;}
        }

        ll uFind(ll x){
            while(Link[x]!=x)x=Link[x];
            return x;
        }

        ll uSame(ll a,ll b){
            return uFind(a)==uFind(b);
        }
        void uUnion(ll large, ll small){
            large=uFind(large);
            small=uFind(small);
            if(large==small)return;
            if(Size[large]<Size[small])swap(large,small);
            Size[large]+=Size[small];
            Link[small]=large;
        }
};
class graphUtil{
    //unionFind Implement in its file
};
class graph{

    public:
        //DFS
        void dfs_adj_helper(vector<vector<ll>> &adj,vector<ll> &visited,ll x){
            if (visited[x]) return;
            visited[x] = 1;
            // cout<<x<<" ";
            for (auto u: adj[x]) 
                dfs_adj_helper(adj,visited,u);
            
        }   
        void dfs_adj(vector<vector<ll>> &adj,ll x){
            vector<ll> visited(adj.size(),0);
            dfs_adj_helper(adj,visited,x);
            for(ll i=0;i<visited.size();i++)
                if(visited[i]==0)
                    dfs_adj_helper(adj,visited,i);
        }



        //BFS
        void bfs_adj_helper(vector<vector<ll>> &adj,vector<ll> &visited,vector<ll> &distance,ll x){
            queue<ll> q;
            visited[x] = 1;
            // distance[x] = 0;
            q.push(x);
            while (!q.empty()) {
                ll s = q.front(); q.pop();
                // process node s
                for (auto u : adj[s]) {
                    if (visited[u]!=-1) continue;
                    visited[u] = 1;
                    distance[u] = distance[s]+1;
                    q.push(u);
                }
            }

        }
		void bfs_adj(vector<vector<ll>> &adj,ll s){
			vector<ll> visited(adj.size(),-1);
            vector<ll> distance(adj.size(),0);
            // ll cnt=0;
            distance[s]=0;
            bfs_adj_helper(adj,visited,distance,s);
            // for(ll i=0;i<adj.size();i++)
            //     if(visited[i]==-1){distance[i]=0;
            //         bfs_adj_helper(adj,visited,distance,i);}
        }
    private:

};
class graphShortestPath{
    public:
        //dijkstra doesnt handle negative weight O(V+ELog(E))
        vector<ll> dijkstra(vector<vector<pair<ll,ll>>>&adj,ll x){
            vector<ll> distance(adj.size(),INT_MAX),processed(adj.size(),-1);
            // for (ll i = 1; i <= n; i++) distance[i] = INF;
            priority_queue<pair<ll,ll>> q;
            distance[x] = 0;
            q.push({0,x});
            while (!q.empty()) {
                ll a = q.top().second; q.pop();
                if (processed[a]) continue;
                    processed[a] = true;
                for (auto u : adj[a]) {
                    ll b = u.first, w = u.second;
                    if (distance[a]+w < distance[b]) {
                        distance[b] = distance[a]+w;
                        q.push({-distance[b],b});
                    }
                }
            }
            return distance;
        }

        //BellmanFord Also handle and detect negative weight O(VE)
        vector<ll> bellmanFord(vector<vector<pair<ll,ll>>>&adj,ll x){//Take care of input adj format or change below
            vector<ll> distance(adj.size(),INT_MAX);
            distance[x] = 0;
            //Converting adjList to edge list with tuple
            vector<tuple<ll,ll,ll>> edges;
            for(ll i=0;i<adj.size();i++)
                for(ll j=0;j<adj[i].size();j++)
                    edges.push_back({i,adj[i][j].first,adj[i][j].second});
            for (ll i = 1; i <= adj.size()-1; i++) {    //Simple loop n-1 times add one more round for detecting negative cycle
                for (auto e : edges) {
                    ll a, b, w;
                    tie(a, b, w) = e;
                    if(distance[a]!=INT_MAX) 
                        distance[b] = min(distance[b], distance[a]+w);
                }
            }
        }
        //FloydWarshall used for all pair shortest path O(V^3)
        void floydWarshall(vector<vector<pair<ll,ll>>>&adj){
            ll n=adj.size();
            vector<vector<ll>> distance(n,vector<ll>(n,INT_MAX));
            //Preprocessing
            for(ll i=0;i<adj.size();i++)
                for(ll j=0;j<adj[i].size();j++){
                    if(i==j)distance[i][j]=0;
                    else distance[i][adj[i][j].first]=adj[i][j].second;
                }        
            //Distance calculation
            for (int k = 0; k < n; k++) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if(distance[i][k]!=INT_MAX&&distance[k][j]!=INT_MAX)
                            distance[i][j] = min(distance[i][j],distance[i][k]+distance[k][j]);
                    }
                }
            }
        }
};
class graphBfsDfsUtil{
    public:
        //Connected Component using BFS
        ll connectedComp(vector<vector<ll>> &adj){
            
            //Stores min max of each connected component also its size give total number of connected component
            v<pair<ll,ll>> mnmx;
            vector<ll> visited(adj.size(),-1);
            vector<ll> distance(adj.size(),0);
            ll cnt=0;

            cnt++;
            //Entry point 0 , can be changed
            distance[0]=0;
            bfsConnectedComp(adj,0,mnmx,visited,distance);

            for(ll i=0;i<adj.size();i++)
                if(visited[i]==-1){
                    cnt++;
                    distance[i]=cnt*adj.size();
                    bfsConnectedComp(adj,i,mnmx,visited,distance);
                }

            // return mnmx;
            return cnt;
        }

        //returns size of connected comp
        ll bfsConnectedComp(vector<vector<ll>> &adj,ll x,v<pair<ll,ll>>&mnmx,v<ll>&visited,v<ll>&distance){

            ll mn=x,mx=x,Size=1;
            queue<ll> q;
            visited[x] = 1;
            // distance[x] = 0;
            q.push(x);
            while (!q.empty()) {
                ll s = q.front(); q.pop();
                // process node s
                for (auto u : adj[s]) {
                    if (visited[u]!=-1) continue;
                    visited[u] = 1;
                    distance[u] = distance[s]+1;
                    q.push(u);
                    //Updating min-max
                    Size++;
                    mn=min(mn,u);
                    mx=max(mx,u);
                }
            }
            mnmx.pb({mn,mx});
            return Size;
        }


        //Simple
        void bipartite(){
            //Just in bfs filter change it to return bool
            //If any visited node in helper have same distance of 0 and 1
            // Then return true/false
        }
        //Finding Cycle in graph
        ll findCycle(vector<vector<ll>> &adj){
            //if node ==n-1 and connected component=1 then no cycle, it fails if disconnected component
            //Do topological sort using dfs and if not posiible, then cycle exists
            //if in bfs if we encounter any already visited node
            ll ans=0;
            //exception-if statement if already visited node is parent
            return fc_dfs_adj(adj,0);

        }
        ll fc_dfs_adj_helper(vector<vector<ll>> &adj,vector<ll> &visited,ll x,ll parent){
            if (visited[x]) return 1;
            visited[x] = 1;
            // cout<<x<<" ";
            ll ans=0;
            for (auto u: adj[x]) 
                if(parent!=u)ans+=fc_dfs_adj_helper(adj,visited,u,u);
            return ans;
        }   
        ll fc_dfs_adj(vector<vector<ll>> &adj,ll x){
            ll ans=0;
            vector<ll> visited(adj.size(),0);
            ans+=fc_dfs_adj_helper(adj,visited,x,x);
            for(ll i=0;i<visited.size();i++)
                if(visited[i]==0)
                    ans+=fc_dfs_adj_helper(adj,visited,i,i);
            return ans;
        }
};
class graphRepresentation{
    //adjList to edgeList
    //edgelist to adjlist
    //adjList to 2dmatrix
    //2dmatrix to adjlist
};
class graphMST{

    //Kruskals
    ll kruskal(vector<vector<pair<ll,ll>>> &adj){
        //edges convet to adjacency list first is weight then 1st vertex then 2nd vertex
        ll n=adj.size();
        vector<tuple<ll,ll,ll>> elist;
        //CREATE here elist
        for(ll i=0;i<adj.size();i++)
            for(ll j=0;j<adj[i].size();j++)
                elist.push_back({adj[i][j].second,i,adj[i][j].first});
        sort(elist.begin(),elist.end());
        unionFind uf(n);
        ll mstlength=0;
        for(auto e:elist){
            ll a,b,c;
            tie(a,b,c)=e;
            if(!uf.uSame(b,c)){
                uf.uUnion(b,c);
                mstlength+=a;
            }
    }
    return mstlength;
    }

    //Prims Algorithm
    ll prims(vector<vector<pair<ll,ll>>> &adj){
        //Start from vertex x as first node
        ll x=0,mstlength=0;
        priority_queue<pair<ll,ll>> q;
        // Intial filling queue with edges of one arbitrary vertex
        for(auto j:adj[x])
                q.push({-j.second,j.first});
                
        unionFind uf(adj.size());
        while(!q.empty()){
            ll a=q.top().first,b=q.top().second;
            q.pop();
            if(!uf.uSame(x,b)){
                uf.uUnion(x,b);
                mstlength+=a;
                for(auto j:adj[b])
                    q.push({-j.second,j.first});
            }   
    }
    return -mstlength;
}
};

void input(){
    ll n;
    cin>>n;
    v<v<ll>> adj(n,v<ll>(0,0));
    v<ll> visited(n,0);
    for(ll i=0;i<n;i++){
        ll t1,t2;
        cin>>t1>>t2;
        adj[t1].pb(t2);
        adj[t2].pb(t1);
    }
	graph g;
    g.dfs_adj(adj,1);
    // dfs_adj(adj,visited,5);
	// graph::bfs_adj(adj,5);
}

int main(){
	ios::sync_with_stdio(false), cin.tie(nullptr);
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
    ll T=1;
    //cin>>T;
    for(ll i=1;i<=T;i++){
		// cout<<"Case #"<<i<<": ";
		input();
    }
    return 0;
}