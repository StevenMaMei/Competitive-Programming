#include <bits/stdc++.h>

using namespace std;

int mod = 10;
int binpow(int a,int b){
    int ans = 1;
    while(b){
        if(b&1) {
            ans *= a;
            ans %=mod;
        }
        a = a*a;
        a %= mod;
        b >>=1;
    }
    return ans;
}
int main()
{
    int n; cin>>n;
    cout<<binpow(8,n)<<"\n";
    return 0;
}
