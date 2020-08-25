#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b; i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())
using namespace std;
typedef long long ll;
const int N = 1e7;
ll s[N];
int A,B,C,D;
int main()
{FIN;
    cin>>A>>B>>C>>D;
    for(int i = A; i<=B;i++){
        s[i+B]++;
        s[i+C+1]--;
    }
    for(int i=1;i<N;i++){
        s[i]+=s[i-1];
    }
    for(int i=1;i<N;i++)s[i]+=s[i-1];
    ll ans =0 ;
    fore(i,C,D+1){
        ans+= s[N-1]-s[i];
    }
    cout<<ans<<"\n";
    return 0;
}
