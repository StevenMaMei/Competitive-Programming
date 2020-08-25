#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;
vector<vector<int>> grid;

int cnt(int a,int b,int c,int d){
    int ans = 0;
    for(int i = a; i<=c; i++){
        for(int j = b; j<=d; j++){
            ans += grid[i][j];
        }
    }
//    cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<ans<<"\n";
    return ans;
}
int main(){FIN;
    int n,m; cin>>n>>m;
    grid.resize(n, vector<int>(m));
    fore(i,0,n){
        fore(j,0,m){
            cin>> grid[i][j];
        }
    }
    int a,b; cin>>a>>b;
    int mn = 1e9;
    fore(i,0,n){
        fore(j,0,m){
            if(i+a-1<n && j+b-1<m){
                mn = min(mn, cnt(i,j,i+a-1,j+b-1));
//            cout<<i<<" "<<j<<" "<<mn<<"\n";
            }
            if(i+b-1<n && j+a-1<m){
                mn = min(mn, cnt(i,j,i+b-1,j+a-1));
            }
        }
    }
    cout<<mn<<"\n";
    return 0;
}
