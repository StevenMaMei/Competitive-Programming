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
    int t; cin>>t;
    while(t--){
        int n,s,k; cin>>n>>s>>k;
        set<int> sett;
        int idxmin=1e9, idxmax = 0;
        fore(i,0,k){
            int a; cin>>a;
            idxmin= min(idxmin,a);
            idxmax = max(idxmax,a);
            sett.insert(a);
        }
        if(sett.count(s)==0){
            cout<<"0\n";
            continue;
        }
        auto it1 = sett.upper_bound(s);
        int mn = (idxmax+1<=n)?abs(idxmax+1-s):1e9;
        if(idxmin>1)mn = min(mn, abs(idxmin-1 -s));
        int last = s;
        while(it1 != sett.end()){
            if(*it1 > last+1){
                mn = min(mn, abs(last+1-s));
                break;
            }else{
                last = *it1;
            }
            ++it1;
        }
        it1= sett.upper_bound(s);
        it1--;
        last = s;
        while(it1 != sett.begin()){
            if(*it1 < last-1){
                mn = min(mn, abs(s-(last-1)));
            }else{
                last = *it1;
            }
            --it1;
        }
        if(*it1< last-1){
            mn = min(mn, abs(s-(last-1)));
        }
        cout<<mn<<"\n";
    }
    return 0;
}
