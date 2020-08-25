#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b; i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())
using namespace std;

int main()
{FIN;
    int n,m; cin>>n>>m;
    int sum = 0;
    fore(i,0,m){
        int a; cin>>a;
        sum+= a;
    }
    n-= sum;
    if(n<0)cout<<"-1\n";
    else cout<<n<<"\n";
    return 0;
}
