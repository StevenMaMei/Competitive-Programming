#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)
typedef long long int ll;
using namespace std;
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
        ll a, b; cin>>a>>b;
        ll diff = max(a,b)-min(a,b);
        ll cant =0;
        cant+= diff/5;
        diff= diff%5;
        cant+=diff/2;
        diff= diff%2;
        cant+= diff;
        cout<<cant<<endl;
    }
    return 0;
}
