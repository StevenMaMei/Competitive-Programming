#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;
string s;

int main(){FIN;
    int t; cin>>t;
    while(t--){
        cin>>s;
        vector<char> pari[2];
        fore(i,0,sz(s)){
            pari[(s[i] -'0')%2].pb(s[i]);
        }
        reverse(pari[0].begin(), pari[0].end());
        reverse(pari[1].begin(), pari[1].end());
        string ans = "";
        while(!(pari[0].empty() && pari[1].empty())){
            if(pari[0].empty()){
                while(!pari[1].empty()){
                    ans += pari[1].back();
                    pari[1].pop_back();
                }
                continue;
            }
            if(pari[1].empty()){
                while(!pari[0].empty()){
                    ans += pari[0].back();
                    pari[0].pop_back();
                }
                continue;
            }

            if(pari[0].back()<pari[1].back()){
                ans += pari[0].back();
                pari[0].pop_back();
            }else{
                ans += pari[1].back();
                pari[1].pop_back();
            }

        }
        cout<<ans<<"\n";
    }
    return 0;
}
