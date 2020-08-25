#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;
typedef long long ll;

class SwapTheString{
    public:
    long long findNumberOfSwaps(string p, int a0, int x, int y, int N, int k){
        ll a[N+5];
        a[0]=a0;
        for(int i = 1; i<N; i++)a[i]=(a[i-1]*x+y)%1812447359;
        string s= p;
        for (ll i = p.length(); i <= N - 1; i++)
            s += (char)(a[i] % 26 + 'a');

        string gr[k+5];
        for(ll i =0; i<k;i++)gr[i]="";
        for(ll i=0;i<N;i++){
            gr[i%k]+= s[i];
        }
        ll ans=0;
        for(ll i = 0; i<k;i++){
            ll freq[30];
            fore(i,0,30)freq[i]=0;
            for(ll j= ll(gr[i].length()-1); j>=0;j--){
                for(ll c = ll(gr[i][j]-'a')+1;c<=26;c++ ){
                    ans += freq[c];
                }
                freq[(gr[i][j]-'a')]++;
            }
        }
        return ans;
    }



};



