#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,thx=b; i<thx;i++)
#define pb push_back
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) s.size()
using namespace std;

int main()
{FIN;
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        string s; cin>>s;
        bool firstCheck= false;
        if( int(s[sz(s)-1]-'0') % 2 != 0){
            int sum = 0;
            fore(i,0,n){
                sum += int(s[i]-'0');
            }
            if( sum %2 == 0) firstCheck=true;
        }
        if(firstCheck){
            cout<<s<<"\n";
        }else{
            vector<char> a;
            fore(i,0,n){
                if(int(s[i]-'0') % 2 != 0){
                    a.pb(s[i]);
                }
                if(sz(a)== 2){
                    break;
                }
            }
            if(sz(a)<2) cout<<"-1\n";
            else{
                fore(i,0,2){
                    cout<<string(1,a[i]);
                }
                cout<<"\n";
            }
        }
    }
    return 0;
}
