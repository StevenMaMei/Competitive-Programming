#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b; i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())
using namespace std;
typedef long long ll;
const int N = 1e6+5;
ll lp[N];
int main()
{FIN;
    fore(i,2,N){
        if(lp[i] == 0){
            for(int j = i; j<N;j+=i){
                if(lp[j]== 0){
                    lp[j]=i;
                }
            }
        }
    }
    int t; cin>>t;
    while(t--){
        ll n,k; cin>>n>>k;
        ll ans = n+lp[n];
        k--;
        ans+= 2*k;

        cout<<ans<<"\n";


    }
    return 0;
}
