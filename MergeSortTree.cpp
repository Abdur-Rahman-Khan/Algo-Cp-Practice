#include<bits/stdc++.h>
using namespace std;

void Merge(vector <int> &arr,vector <int> &arr2,vector <int> &arr3){
    int i=0,j=0;
    while(i<arr2.size()&&j<arr3.size()){
        if(arr2[i]<arr3[j]){
            arr.push_back(arr2[i]);
            i++;
        }
        else{
            arr.push_back(arr3[j]);
            j++;
        }
    }
    while(i<arr2.size()){
            arr.push_back(arr2[i]);
            i++;
    }
    while(j<arr3.size()){
            arr.push_back(arr3[j]);
            j++;
    }
}
void mergeSort(vector <int> &arr,vector <vector<int>> &arr1,int l,int r,int n){
    vector <int> arr2,arr3;
   // printf("%d\n",n);
    if(l==r){
        arr1[n].push_back(arr[l]);
        return;
    }
    //printf("%d\n",n);
   // arr1.resize(max((int)arr1.size(),2*n+3));
    mergeSort(arr,arr1,l,l+((r-l)/2),2*n+1);
    mergeSort(arr,arr1,l+((r-l)/2)+1,r,2*n+2);
    Merge(arr1[n],arr1[2*n+1],arr1[2*n+2]);
    //printf("%d %d %ld %ld %ld\n",l,r,arr1.size(),arr2.size(),arr3.size());
    return ;
}
void printA(vector<vector<int>> arr,int l,int r,int n){
    int i,j;
   // printf("A%dA\n",n);
    if(l==r){
        printf("%d %d\n",n,arr[n][0]);
        return ;
    }
   // printf("A%dA\n",n);
    printA(arr,l,l+((r-l)/2),2*n+1);
    printA(arr,l+((r-l)/2)+1,r,2*n+2);
    printf("%d ",n);
    for(i=0;i<arr[n].size();i++)
        printf("%d ",arr[n][i]);
    printf("\n");
}
int main(){
    int i,n,t;
    vector <int> arr;
    vector <vector<int>> arr1;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&t);
        arr.push_back(t);
    }
    arr1.resize(4*n+1);
    mergeSort(arr,arr1,0,n-1,0);
    printf("%ldA\n",arr1.size());
    // for(i=0;i<arr1.size();i++){
    //     printf("%d ",arr1[i].size());
    // }
    // printf("\n");
    // for(i=0;i<arr1.size();i++){
    //     printf("%d  ",arr1[0][i]);
       printA(arr1,0,n-1,0);
    //  }

    return 0;
}