#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i =low;i<n;i++)

using namespace std;
typedef pair<int,int> ii;
vector<ii> pairs;
int main()
{
    int n,sx,sy; cin>>n>>sx>>sy;
    fore(i,0,n){
        int x,y; cin>>x>>y;
        pairs.pb({x,y});
    }
    vector<pair<ii,int>>ads;
    ads.pb({{sx+1,sy},0});
    ads.pb({{sx-1,sy},0});
    ads.pb({{sx,sy+1},0});
    ads.pb({{sx,sy-1},0});
    fore(i,0,n){
        fore(j,0,4){
            if(min(sx,pairs[i].ff)<= ads[j].ff.ff && ads[j].ff.ff <= max(sx,pairs[i].ff) && min(sy,pairs[i].ss)<=ads[j].ff.ss && ads[j].ff.ss <= max(sy,pairs[i].ss)){
                ads[j].ss++;
            }
        }
    }
    pair<ii,int> maxi= ads[0];
    fore(i,1,4){
        if(maxi.ss<ads[i].ss){
            maxi = ads[i];
        }
    }
    cout<<maxi.ss<<endl;
    cout<<maxi.ff.ff<<" "<<maxi.ff.ss<<endl;
    return 0;
}
