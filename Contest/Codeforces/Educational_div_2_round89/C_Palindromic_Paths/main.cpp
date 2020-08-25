#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> ii;


int main(){FIN;
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        vector<vector<int>> a(n,vector<int>(m));
        fore(i,0,n){
            fore(j,0,m){
                cin>>a[i][j];
            }
        }
        vector<vector<int>> cnt(n+m,vector<int>(2));
        fore(i,0,n){
            fore(j,0,m){
                cnt[i+j][a[i][j]]++;
            }
        }
        int ans = 0;
        for(int i = 0; i <= m+n-2; i++){
            int j = m+n-2-i;
            if(i<=j)continue;
            ans += min(cnt[i][0] + cnt[j][0], cnt[i][1] +  cnt[j][1]);
        }
        cout<<ans<<"\n";
    }

    return 0;
}
