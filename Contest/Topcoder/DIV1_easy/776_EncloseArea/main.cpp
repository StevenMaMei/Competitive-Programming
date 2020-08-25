#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;

class EncloseArea{

    void toggle(vector<vector<char>> &grid,int r,int c, char wanted){
        if(grid[r][c]==wanted)grid[r][c]='.'; else grid[r][c]=wanted;
    }
    public: vector <string> enclose(int A){
        vector<string> noCase;
        if(A%2|| A> 2402)return noCase;

        int need = A/2;
        vector<int> X(need), Y(need);
        int id=0;
        for(int x=0; x<=24;x++)for(int y=x;y<=48-x;y++){
            if(id<need){
                X[id]=x;
                Y[id]=y;
                id++;
            }
        }
        for(int x=-1; x>=-24;x--)for(int y=-x;y<=48+x;y++){
            if(id<need){
                X[id]=x;
                Y[id]=y;
                id++;
            }
        }
        vector<vector<char>>grid(50,vector<char>(50));
        fore(i,0,50)fore(j,0,50)grid[i][j]='.';

        for(int i = 0; i<need; i++){
            int dr= Y[i]-X[i],dc=Y[i]+X[i];
            toggle(grid,dr,dc,'/');
            toggle(grid,dr+1,dc,'\\');
            toggle(grid,dr,dc+1,'\\');
            toggle(grid,dr+1,dc+1,'/');
        }
        vector<string> toR;
        for(int i =0; i<50;i++){
            string ans="";
            for(int j=0; j<50;j++){
                ans += grid[i][j];
            }
            toR.pb(ans);
        }
        return toR;
    };
};

//int main(){FIN;
//
//    return 0;
//}
