#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;
typedef long long ll;
typedef pair<long,long> ii;

const int MAXN= 2005;

ii cords[MAXN];
ll stationCost[MAXN];
ll wireCost[MAXN];
bool used[MAXN];
int parent[MAXN];

int main(){FIN;
    int n; cin>>n;
    fore(i,0,n){
        int a,b; cin>>a>>b;
        cords[i]={a,b};
        parent[i]=-1;
    }
    ll ans=0;
    ll numStations=0;
    ll numConects=0;
    vector<int> statIndx;
    vector<ii>edges;
    fore(i,0,n){
        ll c; cin>>c;
        stationCost[i]=c;
    }
    fore(i,0,n)cin>> wireCost[i];

    fore(i,0,n){
        ll mn=9e18;
        ll mnIndx=-1;
        fore(j,0,n){
            if(used[j])continue;
            if(stationCost[j]<mn){
                mn=stationCost[j];
                mnIndx=j;
            }
        }
        used[mnIndx]=true;
        ans += mn;
        if(parent[mnIndx]==-1){
            statIndx.pb(mnIndx+1);
            numStations++;
        }else{
            numConects++;
            edges.pb({parent[mnIndx]+1, mnIndx+1});
        }
        fore(j,0,n){
            ll cost = (wireCost[mnIndx]+wireCost[j]) * ( abs(cords[mnIndx].ff - cords[j].ff) + abs( cords[mnIndx].ss - cords[j].ss ) );
            if(cost< stationCost[j]){
                stationCost[j]=cost;
                parent[j]=mnIndx;
            }
        }
    }
    cout<<ans<<"\n";
    cout<<numStations<<"\n";
    fore(i,0,sz(statIndx)){
        if(i+1==sz(statIndx)){
            cout<<statIndx[i]<<"\n";
        }else{
            cout<<statIndx[i]<<" ";
        }
    }
    cout<<numConects<<"\n";
    fore(i,0,sz(edges)){

        cout<<edges[i].ff<<" "<<edges[i].ss<<"\n";

    }
    return 0;
}
