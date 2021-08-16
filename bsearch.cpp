#include<bits/stdc++.h>
using namespace std;

int bs(vector <int> &V,int num,int l,int r){
    int mid=l+(r-l)/2;
    if(num==V[mid])
        return 1;
    if(l==r)
        return 0;
    if(num<V[mid]){
        return bs(V,num,l,mid);
    }
    else{
        return bs(V,num,mid+1,r);
    }

}

int main(){
    vector <int> V;
    int n,i,j;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>j;
        V.push_back(j);
    }
    for(i=0;i<n;i++){
        cin>>j;
        cout<<bs(V,j,0,n-1);
    }
    // for(i=0;i<n;i++){
    //     cout<<V[i]<<endl;
    // }
    return 0;
}