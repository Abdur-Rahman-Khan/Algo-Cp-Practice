#include<bits/stdc++.h>
using namespace std;

int cap[101],n,ans;

int solve(int arr[][101],int p){
    printf("%d %d \n",ans,p);
    int i,j,temp=0;
    if(p>=n)
        return 0;
    for(i=1;i<=arr[p][0];i++){
        if(cap[arr[p][i]]==-1){
            cap[arr[p][i]]=1;
            if(p==n-1)
                temp+=1;
            ans+=solve(arr,p+1);
            cap[arr[p][i]]=-1;
        }
    }
    return temp;
}

void input1(){
    int arr[10][101],i,j,temp;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i][0]);
        for(j=0;j<arr[i][0];j++){
            scanf("%d",&arr[i][j+1]);
        }
    }
    memset(cap,-1,sizeof(cap));
    ans=0;
    solve(arr,0);
    printf("Answer-> %d\n",ans);
}

int main(){
    input1();
    return 0;
}