#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a, thxicesi=b; i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0);cin.tie(0)

using namespace std;
vector<vector<int>> graph;
vector<bool> visited;
int n,k;
string s;
int bfs(int u){
    vector<int> letters(28);
    queue<int> q;
    q.push(u);
//    cout<<"--------------------------------------------"<<endl;
    while(q.size()){
        int curr = q.front();
//        cout<<curr<<endl;
        q.pop();
        if(!visited[curr]){
            letters[s[curr]-'a']++;
            visited[curr] = true;
            for(int next : graph[curr]){
                if(!visited[next]){
                    q.push(next);
                }
            }
        }
    }
    int mx = -1;
    int mxpos=0;
    fore(i,0,letters.size()){
//        cout<<i<<" "<<letters[i]<<endl;
        if(mx < letters[i]){
            mx = letters[i];
            mxpos=i;
        }
    }
    int acum = 0;
    fore(i,0,letters.size()){
        if(i != mxpos){
            acum+= letters[i];
        }
    }
//    cout<<" fin --------------------------------------------------- fin"<<endl;
    return acum;
}
int main()
{FIN;
    int t; cin>>t;
    while(t--){
        graph.clear();
        visited.clear();
         cin>>n>>k;
        cin>>s;
        graph.resize(n);
        visited.resize(n);
        fore(i,0,k+1){
            for(int j=i;j<n;j+= k){
                graph[i].pb(j);
                graph[j].pb(i);
                graph[j].pb(n-j-1);
                graph[n-j-1].pb(j);
            }
        }
        int res = 0;
        fore(i,0,n){
            if(!visited[i]){
                res+= bfs(i);
            }
        }

        cout<<res<<"\n";
    }
    return 0;
}
