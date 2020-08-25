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
ll mod = (1e9)+7;

int main(){FIN;
    int h,w; cin>>h>>w;
    vector<vector<int>> grid(h+1,vector<int>(w+1));
    bool can=true;
    fore(i,0,h){
        int a; cin>>a;
        if(a==0){
            if(grid[i][0]>1) can=false;
            else{
                grid[i][0]=1;
            }
        }else{
            fore(j,0,a){
                if(grid[i][j]==1){
                    can=false; break;
                }else{
                    grid[i][j]=2;
                }
            }
        }
        if(a<w)grid[i][a]=1;
    }
    fore(i,0,w){
        int a; cin>>a;
        if(a==0){
            if(grid[0][i]>1) can=false;
            else{
                grid[0][i]=1;
            }
        }else{
            fore(j,0,a){
                if(grid[j][i]==1){
                    can=false; break;
                }else{
                    grid[j][i]=2;
                }
            }
        }
        if(a<h){
            if(grid[a][i] >1)can=false;
            else grid[a][i]=1;
        }
    }
    if(!can){
        cout<<"0\n";return 0;
    }
    ll ans=1;
    fore(i,0,h){
        ll cnt=1;
        fore(j,0,w){
            if(grid[i][j]==0){
                cnt = (cnt*2)%mod;
            }
        }
        ans = (ans%mod*cnt%mod)%mod;

    }
    cout<<ans<<"\n";
    return 0;
}
