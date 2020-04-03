#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define SZ(s) int(s.size())
#define fore(i,a,b) for(int i=a,thxicesi=b;i<thxicesi;i++)
#define mx 1000000
using namespace std;
typedef pair<int,int> ii;

int lowestPrime[mx+5];
vector<int> divisors[mx+5], primes;
vector<vector<ii>> graph;

void generatePrimesAndNormalize(){
    primes.pb(1);
    for(int i=2; i<= mx;i++){
        if(!lowestPrime[i]){
            primes.pb(i);
            for(int j= i; j<=mx;j+=i){
                lowestPrime[j] = i;
            }
        }
        divisors[i] = divisors[i/lowestPrime[i]];

        auto it = find(divisors[i].begin(),divisors[i].end(),lowestPrime[i]);

        if(it != divisors[i].end()) divisors[i].erase(it);
        else divisors[i].pb(lowestPrime[i]);
    }
}
int bfs(int ini){
    queue<ii> q;
    vector<int> dist(mx+5,(int)(1e9));
    dist[ini]= 0;
    for(ii i: graph[ini]){
        q.push({i.ff,i.ss});
        dist[i.ff]=1;
    }
    int mnx = 1e9;
    while(q.size()){
        ii curr = q.front();
        q.pop();
        for(ii child : graph[curr.ff]){
            if(dist[child.ff]== (int)(1e9)){
                dist[child.ff] = dist[curr.ff]+1;
                q.push(child);
                //cout<<curr.ff<<" "<<dist[curr.ff]<<endl;
            }else if(curr.ss != child.ss){
                mnx = min(mnx, dist[child.ff]+dist[curr.ff]+1);
            }
        }
    }
    return mnx;
}
int main()
{
    generatePrimesAndNormalize();
    graph.resize(mx+5);

    int n; cin>> n;
    bool ansIsLength1 = false;
    int id = 0;
    fore(k,0,n){
        int a; cin>> a;

        if(divisors[a].empty()){

            ansIsLength1 = true;
        }else{
            if(SZ(divisors[a]) == 1) divisors[a].pb(1);
            int p = divisors[a][0], q = divisors[a][1];
            graph[p].pb({q,id});
            graph[q].pb({p,id++});
        }

    }
    if(ansIsLength1){
        cout<<"1"<<"\n";
    }else{
        int ans = 1e9;
        int lowes= 1e9;
        for(int prime : primes){
            if(prime *prime >mx)
                break;

            ans= min(ans, bfs(prime));
        }
        if(ans == 1e9){
            cout<<"-1"<<"\n";
        }else{

            cout<<ans<<"\n";
        }
    }
    return 0;
}
