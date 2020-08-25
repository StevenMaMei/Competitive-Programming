#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
const int N = int(1e7)+5;

int main(){FIN;
    vector<int> lp(N);
    for(int i = 2; i<N; i++){
        if(lp[i]== 0){
            for(int j = i; j<N; j+= i){
                lp[j]= i;
            }
        }
    }
    int n; cin>>n;
    vector<int> d1,d2;
    fore(i,0,n){
        int a; cin>>a;
        int orig=a;
        set<int> pr;
        while(a>1){
            pr.insert(lp[a]);
            a /= lp[a];
        }
        if(sz(pr)==1){
            d1.pb(-1);
            d2.pb(-1);
            continue;
        }
        auto it = pr.begin();
        d1.pb(*it);it++;
        int n2=1;
        for(; it != pr.end(); it++){
            n2 *= *it;
        }
        d2.pb(n2);
    }
    fore(i,0,n){
        cout<<d1[i]<<" ";
    }
    cout<<"\n";
    fore(i,0,n){
        cout<<d2[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
