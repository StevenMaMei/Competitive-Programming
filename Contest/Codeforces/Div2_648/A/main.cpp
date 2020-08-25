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
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        vector<vector<int>> grid(n,vector<int>(m));
        fore(i,0,n)fore(j,0,m){
            cin>>grid[i][j];
        }
        int dis=0;
        set<int> cols;
        set<int> rows;
        fore(i,0,n){

            fore(j,0,m){
                if(grid[i][j]){
                    cols.insert(j);
                    rows.insert(i);
                }
            }
        }
        int lefCols= m-sz(cols), lefrows= n-sz(rows);
        dis= min(lefCols,lefrows);
        if(dis%2)cout<<"Ashish\n";
        else cout<<"Vivek\n";
    }
    return 0;
}
