#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b; i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())
using namespace std;
typedef long long int ll;
int main()
{FIN;
    int T; cin>>T;
    while(T--){
        ll n,x; cin>>n>>x;
        string s; cin>>s;
        ll cntZeroes= int(count(s.begin(),s.end(),'0'));
        ll balN = cntZeroes - (n - cntZeroes);

        ll currBal= 0;
        bool inf = false;
        ll ans = 0;
        fore(i,0,n){
            if(balN == 0 ){
                if(currBal == x){
                    inf =true; break;
                }
            }else{
                if(abs(x-currBal)% abs(balN) == 0){
                    if( (x-currBal)/balN >= 0) ans++;
                }
            }
            if(s[i]=='0')currBal++;
            else currBal--;
        }
        if(inf){
            cout<<-1<<"\n"; continue;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
