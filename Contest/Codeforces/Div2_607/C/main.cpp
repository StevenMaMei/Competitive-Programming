#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
     freopen("input.txt","r",stdin);
    #else
     #define endl '\n'
    #endif // LOCAL

    int t; cin>>t;
    while(t--){
        int x; cin>>x;
        string s; cin>>s;
        ll len = s.size();
        fore(i,1,x+1){
            //cout<<"len - i "<<i<<" "<<len-i<<endl;
           // cout<<"paste: "<<s[i-1]-1<<endl;
            ll temp = len;
            temp = ( temp +(((temp-i)%mod)*((ll)(s[i-1]-'0'-1)))%mod)%mod;
            len = temp;
            //cout<<"result "<<len<<endl;
            if(s.size()<x){
                string c = s.substr(i,s.size());
                fore(j,0,s[i-1]-'0'-1) s+=c;
            }
        }
        cout<<(len%mod+mod)%mod<<endl;
    }
    return 0;
}
