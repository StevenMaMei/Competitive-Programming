#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)
using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
      freopen("input.txt", "r", stdin);
    #else
      #define endl '\n'
    #endif
    int t; cin>>t;
    while(t--){
        ll n,m; cin>>n>>m;
        vector<ll> w;
        vector<ii> pairs;
        ll cost=0;
        for(int i =0; i < n; i++){
            ll temp; cin>>temp;
            w.pb(temp);
        }
        if(n== 2){
           cout<<-1<<endl;
        }
        else if(m>= n){

            for(int i = 0; i<n-1 ; i++){
                cost=cost+w[i]+w[i+1] ;
                pairs.pb({i+1,i+2});

            }
            cost+= w[0]+w[n-1];
            pairs.pb({1,n});
            m-=n;

            ll mi= 1e8;
            int im= 0;
            ll mi2 = 1e8;
            int im2=0;
            for(int i =0; i< n;i++){
                if(mi>w[i]){
                    im= i;
                    mi=w[i];
                }
            }
            for(int i =0 ; i< n;i++){
                if(mi2>w[i] && im!= i){
                    mi2=w[i];
                    im2=i;
                }
            }
            for(int i =0 ; i<m;i++){
                cost+= mi2+mi;
                pairs.pb({im+1,im2+1});
            }
            cout<<cost<<endl;
            for(int i =0; i< pairs.size();i++){
                ii p = pairs[i];
                cout<< p.ff<<" "<<p.ss<<endl;
            }
        }else{
            cout<<"-1"<<endl;
        }

    }

    return 0;
}
