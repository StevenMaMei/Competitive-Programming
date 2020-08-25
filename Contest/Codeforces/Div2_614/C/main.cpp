#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;
typedef pair<int,int> ii;

int main(){FIN;
    int n,q; cin>>n>>q;
    set<ii> pairs;
    int bad = 0;
    fore(l,0,q){
        int x,y; cin>>x>>y;
        bool was = pairs.count({x,y})?1:0;
        for(int r = x-1; r<=x+1; r++){
            for(int c= y-1; c<=y+1;c++){
                if(r == x) continue;
                if(was){
                    if(pairs.count({r,c})){
                        bad--;
                    }
                }else{
                    if(pairs.count({r,c})){
                        bad++;
                    }
                }
            }
        }
        if(was){
            pairs.erase({x,y});
        }else{
            pairs.insert({x,y});
        }
        if(bad>=1){
            cout<<"NO\n";
        }else{
            cout<<"Yes\n";
        }
    }
    return 0;
}
