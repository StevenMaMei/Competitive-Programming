#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;


int main(){FIN;

    int Q; cin>>Q;
    while(Q--){
        int n,r; cin>>n>>r;
        vector<int> mons;
        set<int> con;
        fore(i,0,n){
            int x;
            cin>>x;
            if(con.count(x)==0){
                mons.pb(x);
                con.insert(x);
            }
        }
        n=sz(mons);
        sort(mons.begin(),mons.end(),greater<int>());
        int acum =0;
        bool first=false;
        int shots=0;
        fore(i,0,n){
            if(acum>=mons[i]&& first){
                break;
            }else{
                shots++;
                acum+=r;
                first=true;
            }
        }
        cout<<shots<<"\n";
    }
    return 0;
}
