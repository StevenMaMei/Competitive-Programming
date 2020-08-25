#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b; i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;
typedef long long ll;
ll N,A,R,M;
const int mxN = 1e5+10;
ll h[mxN],pre[mxN];
ll solve(ll H){
    int pos = lower_bound(h,h+N,H)-h;
    ll p = H*pos - pre[pos];
    ll q = pre[N] - pre[pos] - H * (N-pos);
    ll ans = min(p,q);
    p -=ans;
    q -= ans;
    ans *= M;
    ans += A*p;
    ans += R*q;
    return ans;
}
int main()
{FIN;
    cin>>N>>A>>R>>M;
    fore(i,0,N){
        cin>>h[i];
    }
    sort(h,h+N);
    M = min(M, A+R);
    for(int i=0; i<N;i++){
        pre[i+1]=pre[i]+h[i];
    }
    ll ans = solve(pre[N]/N);
    ans = min(ans, solve(pre[N]/N+1));
    for(int i = 0; i<N;i++){
        ans = min(ans, solve(h[i]));
    }
    cout<<ans<<"\n";

    return 0;
}
