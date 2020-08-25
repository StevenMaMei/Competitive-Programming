#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b; i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())
using namespace std;
typedef long long int ll;

const int N = 1e4+10;
ll totient[N];
void ini(){
    fore(i,0,N) totient[i]=i;
    for(int i = 2; i<=N; i++){
        if(totient[i]== i){
            for(int j= i;j<=N;j+=i){
                totient[j] /= i;
                totient[j] *= (i-1);
            }
        }
    }
}
int main()
{FIN;
    ini();
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        ll tot = 0;
        ll ans = 0;
        fore(i,1,n+1)tot+= totient[i];
        ans = tot*tot;
        cout<<ans<<"\n";

    }
    return 0;
}
