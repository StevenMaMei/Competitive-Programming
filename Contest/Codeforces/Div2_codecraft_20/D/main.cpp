#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thx=b;i<thx;i++)
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> ii;
int n;
vector<vector<ii>> inMatrix;
char rMatrix[1003][1003];

bool connect(int a,int b, int c, int d, char d1, char d2){

    if(inMatrix[c][d].ff == -1){
        rMatrix[a][b] = d1;
        if(rMatrix[c][d] == '\0') rMatrix[c][d] = d2;
        return 1;
    }else{
        return 0;
    }
}

void dfs(int a, int b, char d){
    if(rMatrix[a][b] != '\0') return;
    rMatrix[a][b] = d;
    ii cur = inMatrix[a][b];
    if(b-1 >= 1 && cur.ff == inMatrix[a][b-1].ff && cur.ss == inMatrix[a][b-1].ss){
        dfs(a,b-1,'R');
    }
    if(b+1 <= n && cur.ff == inMatrix[a][b+1].ff && cur.ss == inMatrix[a][b+1].ss){
        dfs(a,b+1,'L');
    }
    if(a-1 >=1 && cur.ff == inMatrix[a-1][b].ff && cur.ss == inMatrix[a-1][b].ss){
        dfs(a-1,b,'D');
    }
    if(a+1 <= n && cur.ff == inMatrix[a+1][b].ff && cur.ss == inMatrix[a+1][b].ss){
        dfs(a+1,b,'U');
    }
}
int main()
{FIN;
    cin>>n;
    inMatrix.resize(n+1,vector<ii>(n+1));
    fore(i,1,n+1){
        fore(j,1,n+1){
            int a,b; cin>>a>>b;
            inMatrix[i][j] = {a,b};
        }
    }

    fore(i,1,n+1){
        fore(j,1,n+1){
            ii cur = inMatrix[i][j];
            if(cur.ff ==-1){
                bool can = (rMatrix[i][j] != '\0');
                if(can == false && i-1 >= 1) can = connect(i,j,i-1,j,'U','D');
                if(can == false && i+1 <= n) can = connect(i,j,i+1,j,'D','U');
                if(can == false && j-1 >= 1) can = connect(i,j,i,j-1,'L','R');
                if(can == false && j+1 <= n) can = connect(i,j,i,j+1,'R','L');
                if(can == false){
                    cout<<"INVALID\n";
                    return 0;
                }
            }else{
                if(cur.ff == i && cur.ss == j) dfs(i,j,'X');
            }
        }
    }
    fore(i,1,n+1){
        fore(j,1,n+1){
            if(rMatrix[i][j] == '\0') {
                cout<<"INVALID\n";
                return 0;
            }
        }
    }
    cout<<"VALID\n";
    fore(i,1,n+1){
        fore(j,1,n+1){
            cout<<rMatrix[i][j];
        }
        cout<<"\n";
    }
    return 0;
}
