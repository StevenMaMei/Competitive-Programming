#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b;i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0);cin.tie(0)

using namespace std;

int main()
{FIN;
    int t; cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> p(n+1);
        vector<int> c(n+1);
        vector<bool> visited(n+1);
        fore(i,1,n+1){
            cin>>p[i];
        }
        fore(i,1,n+1){
            cin>>c[i];
        }
        int ans = int(1e9);
        fore(k,1,n+1){
            if(visited[k])continue;
            vector<int> cycle;
            queue<int> q;
            q.push(k);
            while(q.size()){
                int curr = q.front();
                q.pop();
                if(!visited[curr]){
                    visited[curr] = true;
                    q.push(p[curr]);
                    cycle.pb(curr);
                }
            }
            int m = cycle.size();

            fore(step,1,m+1){
                if(m%step !=0) continue;
                fore(l,0,step){
                    bool can = true;
                    //if(l+step >=m ) break;
                    for(int i=l;i<m;i+=step){
                        if(i+step <m){
                            int n1 = cycle[i];
                            int n2 = cycle[i+step];
                            //cout<<"k "<<n1<<" "<<n2<< " "<<step<<endl;
                            if(c[n1] != c[n2]) can = false;
                        }
                    }
                    if(can) ans= min(step, ans);

                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
