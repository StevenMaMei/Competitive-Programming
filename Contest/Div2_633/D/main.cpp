#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a, thxicesi=b; i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
using namespace std;

int n;
vector<bool> isleaf;
vector<int> distan;
vector<vector<int>> tree;
bool oneCatch=false;
int mn,mx;
int neighs=0;
bool dfs(int u, int p, int d){
    distan[u]=d;
    int cnt = 0;
    bool childL=false,childN=false;
    int lev = 0;
    for(int i : tree[u]){
        if(i != p){
            bool ans = dfs(i,u,d+1);
            if(ans) {
                childL = true;
                lev++;
            }
            else childN = true;
            cnt++;
        }
//        if(i == 1 && !oneCatch) {
//            childL = true;
//            oneCatch= true;
//            lev++;
//        }
    }
    mx -= max(0,lev-1);
    if(cnt == 0) isleaf[u]=1;
    return isleaf[u];
}
int main()
{FIN;
  cin>>n;
    tree.resize(n+1); isleaf.resize(n+1); distan.resize(n+1);
    fore(i,0,n-1){
        int x,y; cin>>x>>y;
        tree[x].pb(y);
        tree[y].pb(x);
    }
//    isleaf[1]=1;
    mn,mx=n-1;
    int start = 1;
    fore(i,1,n+1)if(tree[i].size()!= 1){
        start = i;
        break;
    }
    dfs(start,-1,0);
    bool odd=false,even=false;
    int cl=1;
    fore(i,1,n+1){
        if(isleaf[i]){
                cl++;
            if(distan[i]%2){
                odd =true;
            }else{
                even = true;
            }
        }
    }

    if(odd && even) mn=3;
    else mn=1;
    cout<<mn<<" "<<mx<<"\n";
    return 0;
}
