#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define f first
#define s second

ll T,N,M,ANS,i,temp,temp1;
vector<ll> arr;
vector<pair<ll,ll>> arr2d;
map<ll,ll> map1;
void input(){
    cin>>N>>M;
    arr.clear();
    map1.clear();
    for(i=0;i<N;i++){
        cin>>temp>>temp1;
        map1[temp]=temp1;
        // arr.push_back(temp);
    }
    // for(i=0;i<M;i++){
    //     cin>>temp;
    //     arr.push_back(temp);
    // }
}
ll limit(ll a){
    auto ub=map1.upper_bound(a);
    auto lb=map1.lower_bound(a);
    auto eq=lb;
    lb--;
    //Case 1: first
        if(eq==map1.begin()&&a<=(*eq).first){
            ll x,y;
            x=(*eq).first;
            y=(*eq).second;
            map1.erase(x);
            if(x==y)
                return x;
            map1[x+1]=y;
            return x;
        }
    //Case:2  Last
        if(eq==map1.end()&&a>=(*lb).second){
            ll x,y;
            x=(*lb).first;
            y=(*lb).second;
            map1.erase(x);
            if(x==y)
                return y;
            map1[x]=y-1;
            return y;
        }
    //Case:4  in a range
        if((*lb).first<a&&(*lb).second>a){
            ll x,y;
            x=(*lb).first;
            y=(*lb).second;
            map1.erase(x);
            if(x==y)
                return a;
            map1[x]=a-1;
            
            map1[a+1]=y;
            
            return a;
        }
        if(a==(*lb).second){
            ll x,y;
            x=(*lb).first;
            y=(*lb).second;
            map1.erase(x);
            if(x==y)
                return y;
            map1[x]=y-1;
            return y;
        }
        if((*eq).first==a){
            ll x,y;
            x=(*eq).first;
            y=(*eq).second;
            map1.erase(x);
            if(x==y)
                return x;
            map1[x+1]=y;
            return x;
        }
    //Case:3  In between two diff
        if((((*ub).f)-a)<(a-((*lb).s))){
            ll x,y;
            x=(*ub).first;
            y=(*ub).second;
            map1.erase(x);
            if(x==y)
                return x;
            map1[x+1]=y;
            return x;
        }
        else{
            ll x,y;
            x=(*lb).first;
            y=(*lb).second;
            map1.erase(x);
            if(x==y)
                return y;
            map1[x]=y-1;
            return y;
        }
}
void solve(){
    // auto it=map1.upper_bound(arr[0]);
    // cout<<(*it).f<<" "<<(*it).s<<endl;

    // it=map1.lower_bound(arr[0]);
    // cout<<(*it).f<<" "<<(*it).s<<endl;

    // it=map1.upper_bound(arr[1]);
    // cout<<(*it).f<<" "<<(*it).s<<endl;

    // it=map1.lower_bound(arr[1]);
    // cout<<(*it).f<<" "<<(*it).s<<endl;

    // it=map1.upper_bound(arr[2]);
    // cout<<(*it).f<<" "<<(*it).s<<endl;

    // it=map1.lower_bound(arr[2]);
    // cout<<(*it).f<<" "<<(*it).s<<endl;
    for(i=0;i<M;i++){
        cin>>temp;
        cout<<limit(temp)<<" ";
    }
}

int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        cout<<"Case #"<<i<<": ";
        input();
        solve();
        cout<<endl;
    }
    return 0;
}