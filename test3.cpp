#include<bits/stdc++.h>
using namespace std;
int main(){
    string s,y,word[10];
    int i=0,x[10];
    getline(cin,s);
    getline(cin,y);
    stringstream z(s);
    while(z>>x[i]){
        cout<<x[i]<<endl;
        i++;
    }
    //printf("%sOK\n",(z));
    cout<<s<<" "+y<<endl;
    return 0;
}