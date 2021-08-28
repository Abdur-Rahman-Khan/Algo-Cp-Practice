#include<bits/stdc++.h>
using namespace std;
using ll=int;
#define pb push_back
#define v vector
#define f first
#define s second



void input(){
   ll n,temp;
   v<ll> a,tail;
   cin>>n;
   tail.resize(n,-1);
    for(ll i=1;i<=n;i++){
       cin>>temp;
       a.pb(temp);
    }
  map<ll,ll> len;
  len[a[0]]=0;
  tail[0]=0;
  for(ll i=1;i<n;i++){
    auto itr=len.lower_bound(a[i]);
    if(a[i]<(len.begin()->f)){
      len.erase(len.begin());
      len[a[i]]=i;
      tail[i]=0;
    }
    if(itr==len.end()){
       itr--;
      len[a[i]]=i;
     
      tail[i]=itr->s;
    }
    else{
        itr--;
      temp=itr->second;
      itr++;
      len.erase(itr);
    
      len[a[i]]=i;
      tail[i]=temp;
    }
  }
  cout<<len.size()<<endl;
  ll last;
  auto itr=len.end();
  itr--;
  last=itr->s;
  for(ll i=0;i<len.size();i++){
    cout<<a[last]<<" ";
    last=tail[last];
  }
  cout<<endl;
}

int main(){
      freopen("input.txt","r",stdin);
		  freopen("output.txt","w",stdout);


    ll T=1;
    // cin>>T;
    for(ll i=1;i<=T;i++){
		input();
		
    }
    return 0;
}