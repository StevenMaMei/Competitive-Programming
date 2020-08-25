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
    int q; cin>>q;
    while(q--){
        int n; cin>>n;
        vector<int> eob(3);
        fore(i,0,n){
            string s; cin>>s;
            if(sz(s)%2){
                eob[1]++;
            }else{
                int cnt =0 ;
                fore(j,0,sz(s)){
                    if(s[j]=='0')cnt++;
                }
                if(cnt%2){
                    eob[2]++;
                }else{
                    eob[0]++;
                }
            }
        }
//        cout<<eob[2]<<"ejej\n";
        int ans = eob[0]+eob[1]+(eob[2]/2)*2;
        if(eob[2]%2 && eob[1]>0){
            ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
