#include <bits/stdc++.h>
#define ff first
#define ss secon
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b; i<thxicesi;i++)
using namespace std;

struct Edge
{
    int from, to, capacity, cost;
};

vector<vector<int>> adj, cost, capacity;

const int INF = 1e9;

void shortest_paths(int n, int v0, vector<int>& d, vector<int>& p) {
    d.assign(n, INF);
    d[v0] = 0;
    vector<bool> inq(n, false);
    queue<int> q;
    q.push(v0);
    p.assign(n, -1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int v : adj[u]) {
            if (capacity[u][v] > 0 && d[v] > d[u] + cost[u][v]) {
                d[v] = d[u] + cost[u][v];
                p[v] = u;
                if (!inq[v]) {
                    inq[v] = true;
                    q.push(v);
                }
            }
        }
    }
}

int min_cost_flow(int N, vector<Edge> edges, int K, int s, int t) {
    adj.assign(N, vector<int>());
    cost.assign(N, vector<int>(N, 0));
    capacity.assign(N, vector<int>(N, 0));

    for (Edge e : edges) {
        adj[e.from].push_back(e.to);
        adj[e.to].push_back(e.from);
        cost[e.from][e.to] = e.cost;
        cost[e.to][e.from] = -e.cost;
        capacity[e.from][e.to] = e.capacity;
    }

    int flow = 0;
    int cost = 0;
    vector<int> d, p;
    while (flow < K) {
        shortest_paths(N, s, d, p);
        if (d[t] == INF)
            break;

        // find max flow on that path
        int f = K - flow;
        int cur = t;
        while (cur != s) {
            f = min(f, capacity[p[cur]][cur]);
            cur = p[cur];
        }

        // apply flow
        flow += f;
        cost += f * d[t];
        cur = t;
        while (cur != s) {
            capacity[p[cur]][cur] -= f;
            capacity[cur][p[cur]] += f;
            cur = p[cur];
        }
    }

    if (flow < K)
        return -1;
    else
        return cost;
}
int main()
{
    int r,c; cin>>r>>c;
    char tabl[r][c];
    fore(i,0,r){
        string s; cin>>s;
        fore(j,0,c){
            tabl[i][j] = s[j];
        }
    }
    vector<Edge> edges;
    int posB, posC,posS;
    fore(i,0,r){
        fore(j,0,c){
            int pos = i*c+j;
            if(tabl[i][j]=='.' || tabl[i][j]=='B' || tabl[i][j]=='C'){

                Edge e = {.from= 2*pos, .to = 2*pos+1, .capacity = 1, .cost = 1};
                if(tabl[i][j]=='B' || tabl[i][j]=='C')
                    e={.from= 2*pos, .to = 2*pos+1, .capacity = 0, .cost = 0};
                edges.pb(e);
                if(i-1>=0 && (tabl[i-1][j]=='.' ||tabl[i-1][j]=='F' )){
                    int pos2 =(i-1)*c+j;
                    Edge e = {.from= 2*pos+1, .to = 2*pos2, .capacity = 1, .cost = 0};
                    edges.pb(e);
                }
                if(i+1 < r && (tabl[i+1][j]=='.'|| tabl[i+1][j]=='F')){
                    int pos2 =(i+1)*c+j;
                    Edge e = {.from= 2*pos+1, .to = 2*pos2, .capacity = 1, .cost = 0};
                    edges.pb(e);
                }
                if(j-1>=0 && (tabl[i][j-1]=='.'|| tabl[i][j-1]=='F')){
                    int pos2 =i*c+j-1;
                    Edge e = {.from= 2*pos+1, .to = 2*pos2, .capacity = 1, .cost = 0};
                    edges.pb(e);
                }
                if(j+1 < c&& (tabl[i][j+1]=='.'|| tabl[i][j+1]=='F')){
                    int pos2 =i*c+j+1;
                    Edge e = {.from= 2*pos+1, .to = 2*pos2, .capacity = 1, .cost = 0};
                    edges.pb(e);
                }

            }
            if(tabl[i][j]=='B'){
                posB = pos;
            }
            if(tabl[i][j]=='C'){
                posC = pos;
            }
            if(tabl[i][j]=='F'){
                posS = pos;
                Edge e = {.from= 2*pos, .to = 2*pos+1, .capacity = 2, .cost = 1};
                edges.pb(e);
            }
        }
    }
//    for(Edge e: edges){
//       cout<<e.capacity<<" "<<e.cost<<" "<<e.from<<" "<<e.to<<endl;
//    }

    int posU = 2*r*c+1;
    Edge e1 = {.from= posU, .to = 2*posB+1, .capacity = 1, .cost = 0};
    Edge e2 = {.from= posU, .to = 2*posC+1, .capacity = 1, .cost = 0};
    edges.pb(e1);
    edges.pb(e2);
    //cout<<"jeje"<<endl;
    int res= min_cost_flow(2*r*c+5,edges,2,posU,2*posS+1);
    cout<<res<<endl;

    return 0;
}
