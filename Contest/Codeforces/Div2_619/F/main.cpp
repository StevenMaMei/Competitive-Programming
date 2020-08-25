#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thx=b;i<thx;i++)
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
#define N 1005
using namespace std;
typedef pair<int,int> ii;
int grid[N][N], cost[45][N][N];
bool picked[45];
vector<ii> cells[45];
int n,m,k,r,c,nr,nc;
int dc[4]={0,1,0,-1};
int dr[4]={1,0,-1,0};
queue<ii> q;
void bfs(int col){
    for(int i = 0; i<SZ(cells[col]);i++){
        q.push(cells[col][i]);
        cost[col][cells[col][i].ff][cells[col][i].ss]=0;
    }
    fore(i,0,45)picked[i]=false;
    while(SZ(q)){
        r = q.front().ff;
        c = q.front().ss;
        q.pop();
        if(!picked[grid[r][c]]){
            picked[grid[r][c]]=true;
            fore(i,0,SZ(cells[grid[r][c]])){
                nr = cells[grid[r][c]][i].ff;
                nc = cells[grid[r][c]][i].ss;
                if(cost[col][nr][nc] ==-1){
                    cost[col][nr][nc] = cost[col][r][c]+1;
                    q.push({nr,nc});
                }
            }
        }
        fore(i,0,4){
            nr = r + dr[i];
            nc = c + dc[i];
            if(nr>=0 && nr <n && nc >= 0 && nc <m && cost[col][nr][nc]== -1){

                cost[col][nr][nc] = cost[col][r][c] + 1;
                q.push({nr,nc});
            }
        }

    }
}

int main()
{FIN;
     cin>>n>>m>>k;
     fore(i,0,n){
        fore(j,0,m){
            cin>>grid[i][j];
            cells[grid[i][j]].pb({i,j});
        }
     }
     memset(cost,-1,sizeof(cost));
     fore(i,1,k+1){
        bfs(i);
     }
     int nq; cin>>nq;
     while(nq--){
        int r1,c1,r2,c2; cin>>r1>>c1>>r2>>c2;
        r1--;c1--;r2--;c2--;
        int ans = abs(r1-r2)+abs(c1-c2);
        fore(i,1,k+1){
            ans = min(ans, 1 + cost[i][r1][c1] + cost[i][r2][c2]);
        }
        cout<<ans<<"\n";
     }
    return 0;
}
