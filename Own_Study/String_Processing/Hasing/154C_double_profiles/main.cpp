#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back

using namespace std;
typedef long long int ll;

ll h1[1000005], h2[1000005];
ll p = 23333;
int n,m;
void init(){
    h2[0] = 1;
    for(int i = 1; i<= n;i++){
        h2[i] = h2[i-1]*p;
    }
}

ll solve(ll* h){

    sort(h+1, h+n+1);
    ll cnt=0,ans=0;
    for(int i = 2; i<= n;i++){
        if(h[i]== h[i-1]) ans+= ++cnt;
        else cnt = 0;
    }
    return ans;
}
int main()
{
    cin>>n>>m;
    init();
    for(int i = 0; i<m; i++){
        int a,b; cin>>a>>b;
        h1[a] += h2[b]; h1[b] += h2[a];
    }
    for(int i = 1; i<=n;i++) h2[i] += h1[i];
    cout<<solve(h1)+solve(h2)<<endl;
    return 0;
}
