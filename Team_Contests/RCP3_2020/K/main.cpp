#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;


int main(){FIN;
    int n,m; cin>>n>>m;
    char ans[m+1];
    for(int i = m-n+1; i<=m;i++){
        cin>>ans[i];
    }
    char cip[m+1]; cin>>(cip+1);
//    fore(i,1,m+1) cout<<cip[i]<<"";
    int pos = m-n;
    for(int i =m; i>=n;i--){
        int curr = ans[i]-'a';
        int obj = cip[i]-'a';
        char r = 'a';
        for(int j= 0; j<=25;j++){
            if((curr+j)%26 == obj){
                r = char(j+'a');
                break;
            }
        }
        ans[pos]= r;
        pos--;

    }
    fore(i,1,m+1){
        cout<<ans[i];
    }
    cout<<"\n";
    return 0;
}
