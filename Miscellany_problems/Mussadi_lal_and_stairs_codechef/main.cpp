#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b; i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())
using namespace std;
typedef long long ll;
ll mod = 1000000007;

ll ways[100005];
int main()
{FIN;
    int t; cin>>t;
    ways[1]=1; ways[2]=2; ways[3]=4;
    fore(i,4,100005){
        ways[i] = (ways[i-1]+ways[i-2]+ways[i-3])%mod;
    }
    while(t--){
        int n; cin>>n;
        cout<<ways[n]<<"\n";
    }
    return 0;
}
