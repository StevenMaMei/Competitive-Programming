#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;
typedef long long int ll;
typedef pair<ll,pair<ll,ll>> ii;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCal
     freopen("input.txt","r",stdin);
    #else
     #define endl '\n'
    #endif // LOCL
    int m; cin>>m;
    while(m--){
        ll n,T,a,b; cin>>n>>T>>a>>b;
        int typo[n];
        int mandat[n];

        fore(i,0,n) cin>>typo[i];
        fore(i,0,n) cin>>mandat[i];
        int cantA = 0;
        int cantB = 0;
        map<ll,pair<ll,ll>> times;
        fore(i,0,n){
            if(typo[i]) cantB++;
            else cantA++;
            if(times.find(mandat[i]) != times.end()){
                if(typo[i])times[mandat[i]].ss++;
                else times[mandat[i]].ff++;
            }else{
                if(typo[i])times[mandat[i]].ss = 1;
                else times[mandat[i]].ff = 1;
            }
        }

        vector<ii> tts;
        for(auto p : times){
            tts.pb(p);
        }
        tts.pb({T+1,{0,0}});
        ll currA = 0;
        ll currB = 0;
        ll ans = 0;
        int len = tts.size();
        fore(i,0,len){
            auto p = tts[i];
            ll currT = p.ff;
            ll sobraT = p.ff - a*currA - b*currB - 1;
            if(sobraT >=0){

                ll sobraA = cantA - currA;
                sobraA = min(sobraA, sobraT / a);
                sobraT -= sobraA*a;

                ll sobraB = cantB - currB;
                sobraB = min(sobraB, sobraT /b);
                ans = max(ans, sobraA+sobraB+currA+currB);
            }
            currA += p.ss.ff;
            currB += p.ss.ss;
        }

        cout<<ans<<endl;
    }
    return 0;
}
