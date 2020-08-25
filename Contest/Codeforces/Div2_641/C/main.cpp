#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b; i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())
using namespace std;
typedef long long ll;
vector<int> primes;
void init(int n){

    vector<bool> visited(n+1);
    for(int i = 2; i<=n;i++){
        if(visited[i] == false){
            for(int j= 2*i; j<=n;j+=i) visited[j]=true;
            primes.pb(i);
        }
    }

}
ll binpow(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b&1) ans *= a;
        a *=a;
        b>>=1;
    }
    return ans;
}
map<int,vector<int>> mp;
int main()
{FIN;
    int n; cin>>n;
    init(200000);
    fore(i,0,n){
        int x; cin>>x;
        for(int j = 2; j*j<=x;j++){
            if(x%j==0){
                int cnt = 0;
                while(x%j==0){
                    x /=j;
                    cnt++;
                }
                mp[j].pb(cnt);
            }
        }
        if(x>1)mp[x].pb(1);
    }
    ll ans = 1;
    for(int p: primes){
        if(mp.count(p)== 0 || sz(mp[p])+1<n)continue;
        sort(mp[p].begin(),mp[p].end());
        if(sz(mp[p])==n){
            ans *= binpow(p,mp[p][1]);
        }else{
            ans *= binpow(p,mp[p][0]);
        }
    }
    cout<<ans<<"\n";
    return 0;
}
