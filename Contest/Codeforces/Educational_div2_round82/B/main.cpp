#include <bits/stdc++.h>


using namespace std;
typedef long long int ll;
int main()
{
    int T; cin>>T;
    while(T--){
        ll n,g,b; cin>>n>>g>>b;
        ll half = (n%2 == 0? n/2: n/2+1);
        if(n<g)cout<<n<<"\n";
        else{
            ll ans = half/g;
            ans *= g;

            ans += half%g;
            if(half%g == 0){
                ans += b*(half/g-1);

            }else{
                ans += b*(half/g);
            }
            cout<<max(ans,n)<<"\n";
        }

    }
    return 0;
}
