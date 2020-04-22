#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thx=b;i<thx;i++)
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

using namespace std;
string getString(string s, int n, int k){
    string pre = s.substr(k-1,n-k+1);
    string su = s.substr(0,k-1);
    if(n%2==k%2){
        reverse(su.begin(),su.end());
    }
    return pre+su;
}
int main()
{FIN;
int t; cin>> t;
    while(t--){
        int n; cin>>n;
        string s ; cin>>s;
        string bestS = s; int bestK=1;
        fore(i,2,n+1){
            if(getString(s,n,i)< bestS){
                bestS = getString(s,n,i);
                bestK = i;
            }
        }
        cout<<bestS<<"\n";
        cout<<bestK<<"\n";
    }
    return 0;
}
