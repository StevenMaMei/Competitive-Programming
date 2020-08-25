#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b; i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())
using namespace std;
typedef long long ll;
int main()
{FIN;
    ll x; cin>>x;
    int steps = 0; ll ini = 100;
    while(ini< x){
        ini += ini/100;
        steps++;
    }
    cout<<steps<<"\n";
    return 0;
}
