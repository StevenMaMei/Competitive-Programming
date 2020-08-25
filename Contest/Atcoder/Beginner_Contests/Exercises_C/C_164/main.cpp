#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b; i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())
using namespace std;

int main()
{FIN;
    int N; cin>>N;
    set<string> kinds;
    while(N--){
        string s; cin>>s;
        kinds.insert(s);
    }
    cout<<sz(kinds)<<"\n";
    return 0;
}
