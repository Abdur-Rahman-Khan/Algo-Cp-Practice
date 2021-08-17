#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define f first
#define s second
#define pb push_back
ll T,N,M,ANS,i,temp;
vector<ll> arr,sq;
vector<pair<ll,ll>> arr2d;

void preProcess(){
    for(ll i=0;i<arr.size();i+=(int)sqrt(N)){
        ll temp=0;
        for(ll j=i;j<i+(int)sqrt(N)&&j<arr.size();j++){
            temp+=arr[j];
        }
        sq[i/(int)sqrt(N)]=temp;
        // cout<<i<<" "<<sq[i/(int)sqrt(N)]<<endl;
    }
}
void update(ll ind,ll val){
    temp=arr[ind];
    arr[ind]=val;
    sq[((i/(int)sqrt(N)))]+=(val-temp);
}

// ll overlapQuery(l,r){

// }
// ll partialQuery(l,r){

// }

ll query(ll l,ll r){

    ll ans=0;
    //intial partial
    for(;l%(int)sqrt(N)!=0 && l<=r;l++){
        ans+=arr[l];
    }
    

    //complete overlap
    for(;l+(int)sqrt(N)<=r;l+=(int)sqrt(N)){
        ans+=sq[l/(int)sqrt(N)];
    }


    //final partial
    for(;l<=r;l++){
        ans+=arr[l];
    }
    return ans;
}
void input(){
    cin>>N;
    arr.clear();
    // arr.resize(N);
    sq.resize(sqrt(N)+1,0);
    // cout<<sqrt(N)<<endl;
    for(i=0;i<N;i++){
        cin>>temp;
        arr.pb(temp);
    }
    preProcess();
    // update(3,10);

 
    ll q;
    cin>>q;
    for(i=0;i<q;i++){
        ll l,r;
        cin>>l>>r;
        cout<<query(l,r)<<endl;
    }
    
}


void solve(){

}

int main(){
    // ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        input();
        solve();
    }
    return 0;
}