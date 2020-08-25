#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thx=b;i<thx;i++)
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef pair<int,string> ii;
vector<ii> steps;
void fix(vector<ii> &v){
    vector<ii> aux = v;
    v.clear();
    fore(i,0,SZ(aux)){
        if(aux[i].ff != 0) v.pb(aux[i]);
    }
}
int main()
{FIN;
    int n,m,k; cin>>n>>m>>k;
    int cnt = 0;
    fore(i,1,n+1){
        steps.pb({m-1,"R"});
        cnt += steps.back().ff* SZ(steps.back().ss);
        if(i==1){
            steps.pb({m-1,"L"});
        }else{
            steps.pb({m-1,"UDL"});
        }
            cnt += steps.back().ff* SZ(steps.back().ss);
        if(i==n){
            steps.pb({n-1,"U"});
        }else{
            steps.pb({1,"D"});
        }
        cnt += steps.back().ff* SZ(steps.back().ss);
    }
    if(cnt < k){
        cout<<"NO\n";
        return 0;
    }
    while(cnt >k){
        string tmp = steps.back().ss;
        int cur = steps.back().ff*SZ(tmp);
        steps.pop_back();
        cnt -= cur;
        if(cnt>= k)continue;
        cur = k-cnt;
        if(cur /SZ(tmp)>0){
            steps.pb({cur/SZ(tmp),tmp});
            cnt += steps.back().ff* SZ(steps.back().ss);
        }
        tmp.resize(cur % SZ(tmp));
        if(SZ(tmp)>0){
           steps.pb({1,tmp});
           cnt += steps.back().ff* SZ(steps.back().ss);
        }


    }
    cout<<"YES\n";
    fix(steps);
    cout<<steps.size()<<"\n";
    fore(i,0,SZ(steps)){
        cout<<steps[i].ff<<" "<<steps[i].ss<<"\n";
    }
    return 0;
}
