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

vector<vector<ii>> graph;
vector<pair<ii,int>> ans;
int visited[10000000];
void bfs(){

    queue<int> q;
        //cout<<1<<endl;
    q.push(1);
    while(q.size()){
        int curr = q.front();
        q.pop();

        //cout<<curr<<endl;
        visited[curr] =1;

        for(ii p : graph[curr]){
            if(!visited[p.ff]){
                visited[p.ff]=1;
                ans.pb({{curr,p.ff}, p.ss});
                q.push(p.ff);
            }
        }

    }

}
int main()
{
    int n; cin>>n;
    graph.resize(n+1);
    map<int,vector<int>> bridges;
    for(int i =1; i<=n;i++){
        int nn; cin>>nn;
        for(int j=0;j<nn;j++){
            int bridge; cin>>bridge;
            bridges[bridge].pb(i);
        }
    }
    auto it = bridges.begin();
    while (it != bridges.end())
	{
	    //cout<<it ->first<<endl;
        vector<int> vec = it->second;
        for(int i = 1; i<vec.size();i++){
            graph[vec[i]].pb({vec[i-1],it->first});
            graph[vec[i-1]].pb({vec[i],it->first});
        }
        it++;
	}
	bfs();
	bool can = true;
	for(int i = 1; i<=n;i++){
        if(!visited[i]){
            can= false;
        }
	}
	if(can){
        for(int i =0; i<ans.size();i++){
            cout<<ans[i].ff.ff<<" "<<ans[i].ff.ss<<" "<<ans[i].ss<<"\n";

        }
	}else{
        cout<<"impossible"<<"\n";
	}
    return 0;
}
