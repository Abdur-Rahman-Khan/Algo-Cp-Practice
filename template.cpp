#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define f first
#define s second
ll T,N,M,ANS,i,temp;
vector<ll> arr;
vector<pair<ll,ll>> arr2d;

void input(){
    cin>>N;
    arr.clear();
    for(i=0;i<N;i++){
        cin>>temp;
        arr.push_back(temp);
    }
}

void solve(){

}

int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        input();
        solve();
    }
    return 0;
}