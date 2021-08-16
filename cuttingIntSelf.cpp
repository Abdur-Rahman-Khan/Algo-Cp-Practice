#include<bits/stdc++.h>
using namespace std;
vector<pair<long int, long int>> arr1,arr2;
long int i,N,j,temp,k,a[3][3],T,t,ans,C;
void input(){
    cin>>N>>C;
    //arr.resize(4);
	temp=0;
    ans=N;
     for(i=0;i<N;i++){
         long int n,m;
         cin>>n>>m;
         arr1.push_back(make_pair(n,1));
         arr1.push_back(make_pair(m-1,-1));
     }
    sort(arr1.begin(),arr1.end());
    // for (int i=0; i<N*2; i++)
    // {
    //     cout << arr1[i].first << " "
    //          << arr1[i].second << endl;
    // }
}
void solve(){
   // ans=overlap(1);
   map <int,int,greater <int>> m;
	int last=0;
	int count=0;
	// for(auto x=arr1.begin();x!=arr1.end();x++){
	// 	cout<<(*x).second<<endl;
	// }
	for(auto x:arr1){
		//cout<<x.first<<endl;
		m[count]+=x.first-last;
		last=x.first;
		count+=x.second;
	}
	for(auto x:m){
	//	cout<<x.first<<" "<<x.second<<endl;
		if(C==0)
			break;
		if(C>=x.second){
			ans+=x.second*x.first;
			C-=x.second;
		}
		else{
			ans+=x.first*C;
			C=0;
		}
	}
    cout<<"Case #"<<t<<": ";
    cout<<ans<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%ld",&T);
	 t=1;
	while(T--){
    	input();
    	solve();
        t++;
	}
    return 0;
}