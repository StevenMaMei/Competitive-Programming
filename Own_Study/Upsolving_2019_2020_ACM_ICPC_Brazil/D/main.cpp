#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i = low; i<n;i++)

using namespace std;
typedef pair<int,int> ii;
vector<int> fathers,leaf;
vector<ii> heights;
vector<bool> visited;
vector<vector<int>> tre;
void dfs(int v, int h){
    heights.pb({h,v});
    //cout<<v<<" "<<h<<endl;
    visited[v] = true;
    if(tre[v].size() == 0){
        leaf[v] = 1;
        return;
    }
    for(int i : tre[v]){
        //cout<<v<<" -> "<<i<<endl;
        if(!visited[i])dfs(i,h+1);
    }
}

int dfs1(int v){
    int nchild= 0;
    if(visited[v]) return 0;
    visited[v] = true;
    if(v == 0) return 1;
    //cout<<v<<" "<<fathers[v]<<endl;
    nchild += dfs1(fathers[v])+1;
    //cout<<nchild<<endl;
    return nchild;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,K; cin>>N>>K;

    fathers.resize(N);
    leaf.resize(N);
    tre.resize(N);
    visited.resize(N);

    fore(i,0,N-1){
        int n; cin>> n;
        tre[n-1].pb(i+1);
        fathers[i+1] = n-1;
        //cout<<" jajaja "<<n-1<<endl;

    }
    dfs(0,0);
    sort(heights.begin(),heights.end(),greater<>());
    vector<ii> pairs;
    visited.clear();
    visited.resize(N);
    fore(i,0,N){
        visited[i] = false;
    }
    fathers[0] =-1;
    fore(i,0,heights.size()){
        if(leaf[heights[i].ss]){
            int nc= dfs1(heights[i].ss);
            //cout<<"hhahah"<<heights[i].ff<<" "<<heights[i].ss<<endl;
            pairs.pb({nc,heights[i].ss});
        }
    }
    sort(pairs.begin(),pairs.end(),greater<>());
    int quant = 0;
    fore(i,0,K){
        //cout<<pairs[i].ff<<" "<<pairs[i].ss<<endl;
        quant+= pairs[i].ff;
    }
    cout<<quant<<endl;
    return 0;
}
