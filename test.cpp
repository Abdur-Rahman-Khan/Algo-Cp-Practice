#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define f first
#define s second

ll T,N,M,ANS,i,temp;
vector<ll> arr;
vector<pair<ll,ll>> arr2d;
multimap <ll,ll> m1;
unordered_multiset <string> s1;
priority_queue <pair<ll,ll>> pq;
void input(){
    cin>>N;
    for(i=0;i<N;i++){
        // string temp;
        cin>>temp;
        cin>>ANS;
        pq.push({temp,ANS});
    }
    for(;!pq.empty();){
        cout<<pq.top().f<<endl;
        pq.pop();

    }
}

void solve(){

}

int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    // cin>>t;
    t=1;
    for(int i=1;i<=t;i++){
        input();
        solve();
    }
    return 0;
}