#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;
struct castle{
    int solds, hire,c,maxi;
    vector<int> ports;
};
vector<castle> castles;
typedef pair<int,int> ii;
set<ii> defended;
vector<bool> alreadyDefended;
int main()
{
    int n, m,k; cin>>n>>m>>k;
    castles.resize(n+1);
    alreadyDefended.resize(n+1);
    fore(i,1,n+1){
        int a,b,c; cin>>a>>b>>c;
        castles[i].solds= a;
        castles[i].hire = b;
        castles[i].c = c;
        castles[i].maxi = i;
        castles[i].ports.pb(i);
    }
    fore(i,0,m){
        int u,v; cin>>u>>v;
        castles[v].maxi = max(castles[v].maxi, u);
        castles[u].ports.pb(v);
    }
    bool can = true;
    fore(t,1,n+1){
        castle currCastle = castles[t];
        //cout<<"k "<<k<<" defended "<<defended.size()<<" castle "<< t<<" Solds "<<currCastle.solds<<endl;
        if(k + defended.size()< currCastle.solds){
            can = false;
            break;
        }else{
            if(k < currCastle.solds){
                fore(i,0,currCastle.solds-k){
                    alreadyDefended[defended.begin() -> second]= false;
                    defended.erase(defended.begin());
                }
                k = currCastle.solds;
            }
                //cout<<" to hire "<<currCastle.hire<<endl;
            for(int c: currCastle.ports){
                if(castles[c].maxi == t && !alreadyDefended[c]){
                    defended.insert({castles[c].c,c});
                    alreadyDefended[c] = true;
                    k--;
                }
            }

            k+= currCastle.hire;
        }
    }
    if(can){
        int tot = 0;
        while(k<0){
            if(defended.size() >0){
                defended.erase(defended.begin());
                k++;
            }
        }
        if(k>=0){
            for(auto p : defended){
                tot += p.ff;
            }

        }
        cout<<tot<<endl;
    }else{
        cout<<"-1"<<endl;
    }
    return 0;
}
