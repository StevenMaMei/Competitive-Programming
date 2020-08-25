#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b; i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())
using namespace std;
double pi = 2*acos(0.0);
int main()
{FIN;
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        double t = tan(pi/(2.0*n));
        double ans = 1/t;
        cout<<fixed<<setprecision(9)<<ans<<"\n";
    }
    return 0;
}
