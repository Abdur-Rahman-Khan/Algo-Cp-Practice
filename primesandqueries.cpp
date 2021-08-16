#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define f first
#define s second
ll T,N,M,ANS,i,temp,Q,P,pos,val,S,L,R;
vector<ll> arr,arr1[4];
vector<pair<ll,ll>> arr2d;

ll calcValue(ll i){
    ll count=0;
    
    while(i%P==0){
        if(i==0)
            break;
        count++;
        i/=P;
    }
    return count;
}

ll calcfunc(int i,int S){
    ll temp1,temp2;
    temp1=pow(arr[i],S);
    temp2=pow(arr[i]%P,S);
    return calcValue(temp1-temp2);
}

ll buildST(int s,int li,int ri,int index){
    //cout<<"A";
    if(ri==li){
        //cout<<li<<": "<<calcfunc(li,s)<<endl;
        return arr1[s-1][index]=calcfunc(li,s);
    }
    return arr1[s-1][index]=buildST(s,li,li+(ri-li)/2,2*index+1)+buildST(s,li+1+(ri-li)/2,ri,2*index+2);
}
ll modifyST(int s,int li,int ri,int i){
   // cout<<"B";
    ll x;
    if(pos<li)
        return 0;
    if(ri<pos)
        return 0;
    if(li==ri){
        ll y,z;
        z=arr[pos];
        x=calcfunc(pos,s);
        arr[pos]=val;
        y=calcfunc(pos,s);
        arr1[s-1][i]=y;
        arr[pos]=z;
        return y-x;
    }
    x=(modifyST(s,li,li+(ri-li)/2,2*i+1)+modifyST(s,li+1+(ri-li)/2,ri,2*i+2));
    arr1[s-1][i]+=x;
    return x;
}
ll searchST(int l,int r,int i){
    //cout<<"C";
    //return 1;
    if(l>=L&&r<=R)
        return arr1[S-1][i];
    if(R<l||r<L)
        return 0;
    return searchST(l,l+(r-l)/2,2*i+1)+searchST(l+1+(r-l)/2,r,2*i+2);
}
void solve1(){
    for(i=0;i<=3;i++){
       // S=i+1;
        modifyST(i+1,0,N-1,0);
    }
}
ll solve2(){
    return searchST(0,N-1,0);
}

void input(){
    cin>>N>>Q>>P;
    arr.clear();
    arr1->clear();
    arr1[0].clear();
    arr1[0].resize(4*N+1);
    arr1[1].clear();
    arr1[1].resize(4*N+1);
    arr1[2].clear();
    arr1[2].resize(4*N+1);
    arr1[3].clear();
    arr1[3].resize(4*N+1);
    
    arr.resize(N);
    for(i=0;i<N;i++){
        cin>>temp;
        // arr.push_back(temp);
        arr[i]=temp;
    }
    for(i=0;i<=3;i++)
        buildST(i+1,0,N-1,0);
    //cout<<"Build Ok";
    for(int i=0;i<Q;i++){
        cin>>temp;
        if(temp==1){
            cin>>pos>>val;
            pos--;
            solve1();
             arr[pos]=val;
        }
        else{
            cin>>S>>L>>R;
            L--;
            R--;
            cout<<solve2()<<" ";
        }
    }
}



int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        cout<<"Case #"<<i<<": ";
        input();
        cout<<endl;
        //solve();
    }
    return 0;
}