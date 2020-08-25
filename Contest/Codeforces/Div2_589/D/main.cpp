#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;


int main(){FIN;
    int n,m; cin>>n>>m;
    vector<set<int>> edges(n+1);
    fore(i,0,m){
        int a,b; cin>>a>>b;
        edges[a].insert(b);
        edges[b].insert(a);
    }

    vector<int> group(n+1,-1);
    fore(g,0,3){
        int first=-1;
        fore(i,1,n+1) if(group[i]==-1){
            first=i;break;
        }
        if(first==-1){
            cout<<"-1\n";return 0;
        }
        group[first]=g;
        fore(second,1,n+1){
            if(edges[first].find(second)==edges[first].end() && group[second]==-1 && first!= second){
                group[second]=g;
            }
        }
    }
    vector<vector<int>> groups(3);

    fore(i,1,n+1){
        if(group[i]==-1){
            cout<<"-1\n";return 0;
        }
        groups[group[i]].pb(i);
    }

    int cnt_edges=0;
    fore(i,0,3){
        fore(j,i+1,3){
            for(int first: groups[i]){
                for(int second: groups[j]){
                    if(edges[first].find(second) == edges[first].end()){
                        cout<<"-1\n";return 0;
                    }else{
                        cnt_edges++;
                    }
                }
            }
        }
    }
    if(cnt_edges != m){
        cout<<"-1\n";return 0;
    }
    fore(i,1,n+1)cout<<group[i]+1<<" ";
    cout<<"\n";
    return 0;
}
