#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;
typedef long long ll;

int main(){FIN;
    int t; cin>>t;
    while(t--){
        int n,m,x,y; cin>>n>>m>>x>>y;
        y = min(y,2*x);
        vector<vector<char>> grid(n, vector<char>(m));
        fore(i,0,n)fore(j,0,m){
            cin>>grid[i][j];
        }
        ll ans = 0;
        fore(i,0,n)fore(j,0,m){
            if(grid[i][j]=='.'){
                if(j+1 <m && grid[i][j+1]=='.'){
                    grid[i][j]=grid[i][j+1]='*';
                    ans += ll(y);
                }else{
                    grid[i][j]='*';
                    ans+= ll(x);
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
