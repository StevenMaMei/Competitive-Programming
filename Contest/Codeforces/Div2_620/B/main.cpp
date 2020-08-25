#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thx=b;i<thx;i++)
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<string,int> ii;
set<string> pals;
string s[105];
int main()
{FIN;
    int n,m; cin>>n>>m;
    fore(i,0,n){
        cin>>s[i];
        pals.insert(s[i]);
    }
    string mid ="";
    vector<string> left,right;
    fore(i,0,n){
        string t = s[i];
        reverse(t.begin(),t.end());
        if(t == s[i]){
            mid = t;
        }else if(pals.count(t)>0){
            left.pb(s[i]);
            right.pb(t);
            pals.erase(s[i]);
            pals.erase(t);
        }
    }
    cout<<m*left.size()*2+mid.size()<<"\n";
    fore(i,0,left.size())cout<<left[i];
    cout<<mid;
    reverse(right.begin(),right.end());
    fore(i,0,right.size())cout<<right[i];
    cout<<"\n";

    return 0;
}
