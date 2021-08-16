// { Driver Code Starts
 #include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
        /*You are required to complete this method */
    int atoi(string str)
    {
        //Your code here
        int i,j=1,ans=0;
        for(i=0;i<str.length();i++){
            ans=ans*10+(str[i]-'0');
            if(str[i]-'0'<0||str[i]-'0'>9)
                return -1;
        }
        return ans;
    }
};
bool isprime(uint64_t n) { //determines if n is a prime number
    const int pn = 9, p[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23 };
    for (int i = 0; i < pn; ++i)
        if (n % p[i] == 0) return n == p[i];
    if (n < p[pn - 1]) return 0;
    uint64_t s = 0, t = n - 1;
    while (~t & 1)
        t >>= 1, ++s;
    for (int i = 0; i < pn; ++i) {
        uint64_t pt = PowerMod(p[i], t, n);
        if (pt == 1) continue;
        bool ok = 0;
        for (int j = 0; j < s && !ok; ++j) {
            if (pt == n - 1) ok = 1;
            pt = MultiplyMod(pt, pt, n);
        }
        if (!ok) return 0;
    }
    return 1;
}

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}  // } Driver Code Ends