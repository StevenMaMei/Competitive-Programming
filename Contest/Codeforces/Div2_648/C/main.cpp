#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;
typedef pair<int,int> ii;

int main(){FIN;
    int n; cin>>n;
    map<int,int> a,b;
    fore(i,1,n+1){
        int c; cin>>c;
        a[c]=i;
    }
     fore(i,1,n+1){
        int c; cin>>c;
        b[c]=i;
    }
    vector<int> counter(n+1);
    for(ii currB: b){
        int indx2= a[currB.ff];
        int indx1= currB.ss;
        if(indx1>indx2){
            int rem = n-indx1+indx2;
            counter[rem]++;
        }else{
            counter[indx2-indx1]++;
        }
    }
    int mx=-1;
    fore(i,0,n+1){
        mx= max(mx, counter[i]);
    }
    cout<<mx<<"\n";
    return 0;
}
