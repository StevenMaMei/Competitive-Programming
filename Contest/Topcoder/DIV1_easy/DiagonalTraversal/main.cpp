#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;


int main(){FIN;
    vector<vector<int>> grid(8,vector<int>(8));
    int cnt=0;
    for(int x=0;x<8;x++)for(int y=x;y<8;y++){
        int r=y-x, c=y;
        grid[r][c]=cnt++;
    }
    for(int x=1;x<8;x++)for(int y=x;y<8;y++){
        int r=y, c=y-x;
        grid[r][c]=cnt++;
    }

    fore(i,0,8){
        fore(j,0,8){
            cout<<grid[i][j]<<"     ";
        }
        cout<<"\n";
    }
    return 0;
}
