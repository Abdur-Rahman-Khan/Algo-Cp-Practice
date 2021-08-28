#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define pb push_back
#define v vector
#define f first
#define s 
int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {   int l1=0,l2=0,r1=n-1,r2=m-1,mid;
        int flag=k%2;
        // k=(k/2)*2;
        while(k>0){
            mid=k/2;
			// cout<<"Z"<<k<<endl;
            
            if(l1>r1){
				cout<<"B"<<" ";
                if(k>0){
                    return arr2[l2+k-1];    
                }
                else{
                    return arr1[l1];
                }
            }        
            if(l2>r2){
				cout<<"C"<<" ";
                if(k>0){
					// cout<<k<<endl;
            		return arr1[l1+k-1];      
                }
                else{
                    return arr2[l2];
                } 
            }
			if(k==1){
				cout<<"A"<<" ";
                return min(arr1[l1],arr2[l2]);
            }
            if(l1+mid-1>r1){
                mid=r1-l1+1;
				cout<<"D"<<" ";
                if(arr1[r1]>arr2[l2+mid-1]){
                    k-=mid;
                    l2+=mid;
                }
                else{
                    k-=mid;
                    l1+=mid;
					// l1=r1;
                }
				// l1=r1;
            }
            else if(l2+mid-1>r2){
                mid=r2-l2+1;
				cout<<"E"<<" ";
                if(arr2[r2]>arr1[l1+mid-1]){
                    k-=mid;
                    l1+=mid;
                }
                else{
                    k-=mid;
                    l2+=mid;
					// l2=r2;
                }
		
            }
            else{
				cout<<"F"<<" ";
                if(arr1[l1+mid-1]>arr2[l2+mid-1]){
                    k-=mid;
                    l2+=mid;
                }
                else{
                    k-=mid;
                    l1+=mid;
                }
            }
			// if(l1>r1){
			// 	l1=r1;
			// }
			// if(l2>r2){
			// 	l2=r2;
			// }
            cout<<l1<<" "<<r1<<" "<<l2<<" "<<r2<<" "<<mid<<endl;
        }
		return -1;
    }
void input(){
	int n,m,k;
	cin>>n>>m>>k;
	int arr1[n];
	for(ll i=0;i<n;i++){
		cin>>arr1[i];
	}
	// cin>>m;
	int arr2[m];
	for(ll i=0;i<m;i++){
		cin>>arr2[i];
	}
	// cin>>k;

	cout<<kthElement(arr1,arr2,n,m,k);
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