#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b; i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())
using namespace std;
typedef long long ll;
int mx = 1<<5;
int valVowel(char a){
    if(a == 'a')return 0;
    else if( a== 'e')return 1;
    else if(a == 'i')return 2;
    else if(a=='o')return 3;
    else if(a=='u')return 4;
}
int main()
{FIN;
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        vector<ll> dishes(mx);
        vector<vector<bool>> pairs(mx,vector<bool>(mx));
        fore(i,0,n){
            string s; cin>>s;
            int mask = 0;
            fore(j,0,sz(s)){
                int m = (1<<(valVowel(s[j])));
                mask = (mask|m);
            }
            dishes[mask]++;
        }
        ll ans = 0;
        fore(i,1,mx){
            fore(j,1,mx){
                if( (i|j) == ((mx)-1)){
                    if(pairs[i][j] || pairs[j][i]) continue;
                    if(i==j){
                        ans += dishes[i]*(dishes[i]-1)/2;
                    }else{
                        ans += dishes[i]*dishes[j];
                    }
                    pairs[i][j]= pairs[j][i]=true;
                }
            }
        }
        cout<<ans<<"\n";
    }

    return 0;
}
