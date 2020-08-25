#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;
typedef long long int ll;
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
        ll r,b,k; cin>>r>>b>>k;
        if(r>b)
            swap(r,b);
        ll g = __gcd(r,b);
        r /= g;
        b /= g;

        if((k-1)*r+1<b)
            cout<<"REBEL"<<endl;
        else
            cout<<"OBEY"<<endl;
    }
    return 0;
}
