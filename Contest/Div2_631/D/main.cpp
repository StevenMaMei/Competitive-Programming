#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
int main()
{
    int t; cin>>t;
    while(t--){
        ll d,m;cin>>d>>m;
        ll ans=1;
        for(int i = 0;i<=30;i++){
            if((1<<i) >d) break;
            ll temp = min(ll((1<<(i+1))-1),d);
            temp += m; temp %=m;
            temp -= (1<<i);
            temp += m; temp %=m;
            temp +=2;
            temp += m; temp %=m;
            ans *= temp;
            ans += m; ans%=m;
        }
        ans--;
        ans+= m;
        ans %=m;
        cout<<ans<<"\n";
    }
    return 0;
}
