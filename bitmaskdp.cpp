#include<bits/stdc++.h>
using namespace std;

int cap,n,m,ans,mask,dp[2050][100];

int solve(int arr[][11],int p){
    int i,j,temp=0,ans1=0;
    if(p>=n)
        return 0;
    if(dp[mask][p]!=-1){
        return dp[mask][p];
    }
    cap=solve(arr,p+1);
      //      printf("B %d %d %d %d\n",mask,ans,p,i);
            ans1+=cap;
    for(i=1;i<=arr[p][0];i++){
        // printf("C %d %d %d %d\n",mask,ans,p,i);
        if((mask&(1<<(arr[p][i]-1)))<1){
            mask=mask|(1<<(arr[p][i]-1));
          //  printf("%d %d %d\n",mask,(1<<(arr[p][i]-1)),mask&(1<<(arr[p][i]-1)));
            if(mask==((1<<m)-1)) 
                temp+=1;
        //    printf("A %d %d %d %d\n",mask,ans,p,i);
            cap=solve(arr,p+1);
      //      printf("B %d %d %d %d\n",mask,ans,p,i);
            ans1+=cap;
            dp[mask][p+1]=cap;
            mask=mask^(1<<(arr[p][i]-1));
        }
    }
    ans1+=temp;
    return ans1;
}
void printdp(){
    int i,j;
    for(i=0;i<20;i++){
        for(j=0;j<20;j++){
            printf("%2d ",dp[i][j]);
        }
        printf("\n");
    }
}

void input1(){
    int arr[100][11],i,j,temp;
    scanf("%d %d",&n,&m);
    mask=0;
    
    for(i=0;i<n;i++){
        scanf("%d",&arr[i][0]);
        for(j=0;j<arr[i][0];j++){
            scanf("%d",&arr[i][j+1]);
        }
    }
   // memset(cap,-1,sizeof(cap));
    memset(dp,-1,sizeof(dp));
    ans=0;
    //solve(arr,0);
    printf("Answer-> %d \n",solve(arr,0));
    //printdp();
}

int main(){
    input1();
    return 0;
}