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
typedef pair<int, int> ii;


int main(){FIN;
    int n,m; cin>>n>>m;
    vector<vector<char>> grid(n,vector<char>(m));
    vector<bool> exclude(n+1);
    fore(i,0,n){
        fore(j,0,m){
            cin>>grid[i][j];
        }
    }
    int columns = 0;
//    exit(0);
    fore(i,0,m){
        vector<bool>temp(n+1);
        bool apply= true;
        fore(j,1,n){
            if(!exclude[j] && grid[j][i]< grid[j-1][i]){
                if(apply)
                    columns++;
                apply=false;
            }else if(grid[j][i]>grid[j-1][i]){
                temp[j]=true;
            }
        }
        if(apply){
            fore(j,0,n){
                exclude[j] =( exclude[j] || temp[j]);
            }
        }
    }
    cout<<columns<<"\n";
    return 0;
}
