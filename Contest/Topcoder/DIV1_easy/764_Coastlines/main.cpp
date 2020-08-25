#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;

class Coastlines{
    map<int,int> colorCounting;
    vector<int> dx={0,1,0,-1}, dy={1,0,-1,0};
    void dfs(int x,int y , int color, vector<vector<int>> &grid){
        grid[y][x]=color;
        fore(i,0,4){
            int nx= x+dx[i], ny= y+dy[i];
            if(nx>=0 && ny>=0 && nx<sz(grid[0]) && ny<sz(grid) ){
                if(grid[ny][nx]==0){
                    colorCounting[color]++;
                }else if(grid[ny][nx]==1){
                    dfs(nx,ny,color,grid);
                }
            }else{
                colorCounting[color]++;
            }
        }
    }

    public :  int longest(vector <string> map){
        vector<vector<int>> grid(sz(map), vector<int>(sz(map[0])));
        fore(i,0,sz(map)){
            string s = map[i];
            fore(j,0,sz(s)){
                if(s[j]=='X'){
                    grid[i][j]=1;
                }
            }
        }
        int curColor=2;
        fore(i,0,sz(grid)){
            fore(j,0,sz(grid[0])){
                if(grid[i][j]==1){
                    dfs(j,i,curColor++,grid);
                }
            }
        }
        int mx = 0;
        for(auto p: colorCounting){
            mx= max(mx,p.ss);
        }
        return mx;

    };
};


//int main(){FIN;
//    return 0;
//}
